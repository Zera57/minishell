/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:30:02 by larlena           #+#    #+#             */
/*   Updated: 2021/05/05 19:23:59 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_search_builtin_commands(t_all *all, t_list *parser, char *command)
{
	size_t	len;

	len = ft_strlen(command) + 1;
	if (!ft_strncmp(command, "export", len))
	{
		if (((t_parser *)parser->content)->arg[1])
			ft_export_add(all, ((t_parser *)parser->content));
		else
			ft_export(all);
	}
	else if (!ft_strncmp(command, "unset", len))
		ft_unset(all, ((t_parser *)parser->content));
	else if (!ft_strncmp(command, "exit", len))
		ft_exit(all, ((t_parser *)parser->content));
	else if (!ft_strncmp(command, "echo", len))
		ft_echo(all, ((t_parser *)parser->content));
	else if (!ft_strncmp(command, "cd", len))
		ft_cd(all, ((t_parser *)parser->content));
	else if (!ft_strncmp(command, "pwd", len))
		ft_pwd(all);
	else if (!ft_strncmp(command, "env", len))
		ft_env(all);
	else
		return (-1);
	return (0);
}

static char	**ft_get_path(t_all *all)
{
	t_dictionary	*buf;
	char			**dst;

	buf = ft_dic_get_value(all->env, "PATH");
	if (!buf)
		return (NULL);
	dst = ft_split(buf->value, ':');
	return (dst);
}

static int	ft_executin_command(t_all *all, t_list *parser,
								char *path, char *command)
{
	int		fd;
	char	*tmp;

	ft_rewrite(&path, '/');
	tmp = ft_strjoin(path, command);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	execve(tmp, ((t_parser *)parser->content)->arg, ft_get_env(all));
	free(path);
	free(tmp);
	return (0);
}

int	ft_search_fork_commands(t_all *all, t_list *parser, char *command)
{
	char	**path;
	size_t	i;

	i = -1;
	path = ft_get_path(all);
	if (!path)
		exit(0);
	while (path[++i])
	{
		ft_rewrite(&path[i], '/');
		if (!ft_executin_command(all, parser, path[i], command))
			exit(0);
	}
	free(path);
	exit(0);
}

void	ft_fd_replacement(t_all *all, t_list *begin, t_list *parser)
{
	if (begin == parser)
	{
		dup2(((t_parser *)parser->content)->pipefd[FD_W], FD_W);
		dup2(((t_parser *)parser->next->content)->pipefd[FD_R], ((t_parser *)parser->content)->pipefd[FD_R]);
	}
	else if (parser->next)
	{

	}
	else
	{
		dup2(FD_W, all->dupfdw);
	}
}

int	ft_search_commands(t_all *all, t_list *parser)
{
	ft_fd_replacement(all, all->parser, parser);
	if (!ft_search_builtin_commands(all, parser,
			((t_parser *)parser->content)->arg[0]))
		exit(0);
	ft_search_fork_commands(all, parser,
		((t_parser *)parser->content)->arg[0]);
	return (0);
}
