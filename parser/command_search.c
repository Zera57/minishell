/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:30:02 by larlena           #+#    #+#             */
/*   Updated: 2021/05/23 17:45:15 by larlena          ###   ########.fr       */
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

static char	**ft_get_path(t_all *all, char *command)
{
	t_dictionary	*buf;
	char			**dst;

	if (!ft_strncmp("./", command, 2) || !ft_strncmp("../", command, 3))
		dst = ft_add_present_dir();
	else
	{
		buf = ft_dic_get_value(all->env, "PATH");
		if (!buf)
			dst = ft_calloc(sizeof(char *), 1);
		else
		{
			dst = ft_split(buf->value, ':');
			ft_add_slash(dst);
		}
		dst = ft_add_emty_line(dst);
	}
	return (dst);
}

void	ft_search_fork_commands(t_all *all, t_list *parser, char *command)
{
	char	**path;
	size_t	i;

	i = -1;
	path = ft_get_path(all, command);
	if (!path)
		exit(0);
	while (path[++i])
	{
		if (!ft_executin_command(all, parser, path[i], command))
			exit(0);
		free(path[i]);
	}
	free(path);
}

void	ft_fd_replacement(t_list *begin, t_list *previous, t_list *present)
{
	if (begin == present)
	{
		ft_fd_replacement_first_elem(present);
	}
	else if (present->next != NULL)
	{
		ft_fd_replacement_middle_elem(previous, present);
	}
	else
	{
		ft_fd_replacement_last_elem(previous, present);
	}
}

int	ft_search_commands(t_all *all, t_list *parser)
{
	ft_fd_replacement(all->parser,
		ft_search_previous(all->parser, parser), parser);
	if (!(((t_parser *)parser->content)->redfd[FD_R] < 0)
		&& !(((t_parser *)parser->content)->redfd[FD_W] < 0))
	{
		if (!ft_search_builtin_commands(all, parser,
				((t_parser *)parser->content)->arg[0]))
			exit(all->err);
		ft_search_fork_commands(all, parser,
			((t_parser *)parser->content)->arg[0]);
		exit(127);
	}
	exit(all->err);
}
