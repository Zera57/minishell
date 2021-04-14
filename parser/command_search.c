/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:30:02 by larlena           #+#    #+#             */
/*   Updated: 2021/04/14 19:56:38 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_search_oun_commands(t_all *all)
{
	size_t	i;
	size_t	len;
	char	str[8][8] = {"echo", "cd", "pwd", "export",
						"unset", "env", "exit"};

	i = -1;
	len = ft_strlen(all->parser.arg[0]);
	while(str[++i])
	{
		if (ft_strncmp(all->parser.arg[0], str[i], len))
		{
			
			return (0);
		}
	}
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

static int	ft_executin_command(t_all *all ,char *path, char *filename)
{
	int		fd;
	char	*tmp;

	tmp = ft_strjoin(path, filename);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	execve(tmp, all->parser.arg, ft_get_env(all));
	free(tmp);
	return (0);
}

static int	ft_search_sys_commands(t_all *all)
{
	char	**str;
	size_t	i;

	i = -1;
	str = ft_get_path(all);
	if (!str)
		return (-1);
	while (str[++i])
	{
		if (!ft_executin_command(all, str[i], all->parser.arg[0]))
			return (0);
	}
	ft_free(str);
	return (1);
}

int			ft_command_search(t_all *all)
{
	if (!ft_search_oun_commands(all))
		return (0);
	else if (!ft_search_sys_commands(all))
		return (0);
	else
		return (-1);
}