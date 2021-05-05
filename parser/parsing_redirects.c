/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:41:33 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/26 17:21:07 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_next_word(t_all *all)
{
	int		i;
	char	*str;

	all->j++;
	while (all->str[all->j] == ' ' && all->str[all->j] != 0)
		all->j++;
	i = all->j;
	while (all->str[all->j] != ';' && all->str[all->j] != '|'
		&& all->str[all->j] != '>' && all->str[all->j] != '<'
		&& all->str[all->j] != ' ' && all->str[all->j] != 0)
		all->j++;
	if (all->j == i)
	{
		//error
		printf("error\n");
	}
	str = ft_malloc(all->j - i + 1);
	ft_strlcpy(str, &all->str[i], all->j - i + 1);
	return (str);
}

int	ft_redirect(t_all *all, t_parser *parser)
{
	char	*path;

	path = get_next_word(all);
	parser->fd_w = open(path, O_RDWR | O_CREAT | O_TRUNC);
	if (parser->fd_w < 0)
	{
		printf("Error");
		return (1);
	}
	return (0);
}

int	ft_double_redirect(t_all *all, t_parser *parser)
{
	char	*path;

	all->j++;
	path = get_next_word(all);
	parser->fd_w = open(path, O_RDWR | O_CREAT | O_TRUNC);
	if (parser->fd_w < 0)
	{
		printf("Error");
		return (1);
	}
	return (0);
}

int	ft_reverse_redirect(t_all *all, t_parser *parser)
{
	char	*path;

	path = get_next_word(all);
	parser->fd_r = open(path, O_RDWR | O_CREAT | O_TRUNC);
	if (parser->fd_r < 0)
	{
		printf("Error");
		return (1);
	}
	return (0);
}

int	ft_redirects(t_all *all, t_parser *parser)
{
	if (all->str[all->j] == '>' && all->str[all->j + 1] == '>')
		ft_double_redirect(all, parser);
	else if (all->str[all->j] == '>')
		ft_redirect(all, parser);
	else if (all->str[all->j] == '<')
		ft_reverse_redirect(all, parser);
	return (0);
}
