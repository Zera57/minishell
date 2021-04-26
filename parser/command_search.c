/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:30:02 by larlena           #+#    #+#             */
/*   Updated: 2021/04/26 15:34:29 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_search_builtin_commands(t_all *all, t_list *parser, char *command)
{
	if (!ft_strncmp(command, "export", ft_strlen(command) + 1))
	{
		if (((t_parser *)parser->content)->arg[1])
			ft_export_add(all, ((t_parser *)parser->content));
		else
			ft_export(all);
	}
	else if (!ft_strncmp(command, "unset", ft_strlen(command) + 1))
		ft_unset(all, ((t_parser *)parser->content));
	else if (!ft_strncmp(command, "exit", ft_strlen(command) + 1))
		ft_exit(all, ((t_parser *)parser->content));
	else if (!ft_strncmp(command, "echo", ft_strlen(command) + 1))
		ft_echo(all, ((t_parser *)parser->content));
	else if (!ft_strncmp(command, "cd", ft_strlen(command) + 1))
		ft_cd(all, ((t_parser *)parser->content));
	else if (!ft_strncmp(command, "pwd", ft_strlen(command) + 1))
		ft_pwd(all);
	else if (!ft_strncmp(command, "env", ft_strlen(command) + 1))
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

static int	ft_executin_command(t_all *all, t_list *parser, char *path, char *command)
{
	int		fd;
	char	*tmp;

	path = ft_rewrite(path, '/');
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

int			ft_search_fork_commands(t_all *all, t_list *parser, char *command)
{
	char	**path;
	size_t	i;

	i = -1;
	path = ft_get_path(all);
	if (!path)
		exit(0);
	while (path[++i])
	{
        if (!ft_executin_command(all, parser, ft_rewrite(path[i], '/'), command))
            exit(0);
    }
	free(path);
	exit(0);
}

int			ft_search_commands(t_all *all, t_list *parser)
{
	if (!ft_search_builtin_commands(all, parser, ((t_parser *)parser->content)->arg[0]))
		exit(0);
	ft_search_fork_commands(all, parser, ((t_parser *)parser->content)->arg[0]);
	return(0);
}
