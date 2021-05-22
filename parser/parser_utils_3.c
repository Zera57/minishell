/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zera <zera@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:51:25 by larlena           #+#    #+#             */
/*   Updated: 2021/05/22 14:29:45 by zera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_return_error(char *text, char *arg)
{
	g_all.err = 258;
	ft_error(text, arg);
	return (1);
}

void	ft_skip_space(const char *str, int *i)
{
	while (str[*i + 1] == ' ')
		(*i)++;
}

int	ft_isspecial_symbols(char c)
{
	return (c == '|' || c == ';');
}

char	**ft_add_present_dir(void)
{
	char	**dst;
	char	tmp[1024];

	getcwd(tmp, 1024);
	dst = ft_calloc(sizeof(char *), 2);
	*dst = ft_strdup(tmp);
	ft_add_slash(dst);
	return (dst);
}

int	ft_executin_command(t_all *all, t_list *parser,
								char *path, char *command)
{
	int		fd;
	char	*tmp;

	tmp = ft_strjoin(path, command);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	execve(tmp, ((t_parser *)parser->content)->arg, ft_get_env(all));
	free(tmp);
	return (0);
}
