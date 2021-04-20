/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:30:02 by larlena           #+#    #+#             */
/*   Updated: 2021/04/20 19:19:56 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_search_own_commands(t_all *all, t_list *parser)
{
	if (!ft_strcmp(((t_parser *)parser->content)->arg[0], "export"))
	{
		if (((t_parser *)parser->content)->arg[1])
			ft_export_add(all, ((t_parser *)parser->content));
		else
			ft_export(all);
	}
	else if (!ft_strcmp(((t_parser *)parser->content)->arg[0], "unset"))
		ft_unset(all, ((t_parser *)parser->content));
	else if (!ft_strcmp(((t_parser *)parser->content)->arg[0], "exit"))
		ft_exit(all, ((t_parser *)parser->content));
	else if (!ft_strcmp(((t_parser *)parser->content)->arg[0], "echo"))
		ft_echo(all, ((t_parser *)parser->content));
	else if (!ft_strcmp(((t_parser *)parser->content)->arg[0], "cd"))
		ft_cd(all, ((t_parser *)parser->content));
	else if (!ft_strcmp(((t_parser *)parser->content)->arg[0], "pwd"))
		ft_pwd(all);
	else if (!ft_strcmp(((t_parser *)parser->content)->arg[0], "env"))
		ft_env(all);
	return (-1);
}

static char	**ft_get_path(t_all *all)
{
	t_dictionary	*buf;
	char			**dst;

	buf = ft_dic_get_value(all->env, "PATH");
	if (!buf)
		return (NULL);
	dst = ft_split(buf->value, ':');
	if (!dst)
		return (NULL);
	return (dst);
}

static int	ft_executin_command(t_all *all, t_list *parser, char *path, char *filename)
{
	int		fd;
	char	*tmp;

	path = ft_rewrite(path, '/');
	tmp = ft_strjoin(path, filename);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	execve(tmp, ((t_parser *)parser->content)->arg, ft_get_env(all));
	free(tmp);
	return (0);
}

static int	ft_search_sys_commands(t_all *all, t_list *parser)
{
	char	**str;
	size_t	i;

	i = -1;
	str = ft_get_path(all);
	if (!str)
		return (-1);
	while (str[++i])
	{
		if (!ft_executin_command(all, parser, str[i], ((t_parser *)parser->content)->arg[0]))
			return (0);
	}
	ft_free(str);
	return (1);
}

int			ft_command_search(t_all *all, t_list *parser)
{
	ft_search_own_commands(all, parser);
	ft_search_sys_commands(all, parser);
	exit(0);
}
