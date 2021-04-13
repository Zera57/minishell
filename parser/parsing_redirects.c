/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:41:33 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/12 20:54:49 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_next_word(t_all *all)
{
	int		i;
	int		j;
	char	*str;

	all->parser.i++;
	while (all->str[i] == ' ' && all->str[i] != 0)
		all->parser.i++;
	i = all->parser.i;
	while (all->str[all->parser.i] != ';' && all->str[all->parser.i] != '|'
		&& all->str[all->parser.i] != '>' && all->str[all->parser.i] != '<'
		&& all->str[all->parser.i] != ' ' && all->str[all->parser.i] != 0)
		all->parser.i++;
	if (all->parser.i == i)
	{
		//error
		printf("error\n");
	}
	str = malloc(j - i + 1);
	ft_strlcpy(str, &all->str[i], j - i + 1);
	return (str);
}

int		ft_redirect(t_all *all)
{
	char	*path;

	path = get_next_word(all);
	all->parser.fd_w = open(path, O_RDWR | O_CREAT | O_TRUNC);
	if (all->parser.fd_w < 0)
	{
		printf("Error");
		return (1);
	}
	return (0);
}

int		ft_double_redirect(t_all *all)
{
	char	*path;

	all->parser.i++;
	path = get_next_word(all);
	all->parser.fd_w = open(path, O_RDWR | O_CREAT | O_TRUNC);
	if (all->parser.fd_w < 0)
	{
		printf("Error");
		return (1);
	}
	return (0);
}

int		ft_reverse_redirect(t_all *all)
{
	char	*path;

	path = get_next_word(all);
	all->parser.fd_r = open(path, O_RDWR | O_CREAT | O_TRUNC);
	if (all->parser.fd_r < 0)
	{
		printf("Error");
		return (1);
	}
	return (0);
}

int		ft_redirects(t_all *all)
{
	if (all->str[all->parser.i] == '>' && all->str[all->parser.i + 1] == '>')
		ft_double_redirect(all);
	else if (all->str[all->parser.i] == '>')
		ft_redirect(all);
	else if (all->str[all->parser.i] == '<')
		ft_reverse_redirect(all);
	return (0);
}
