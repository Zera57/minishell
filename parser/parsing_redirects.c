/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:41:33 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 10:52:21 by larlena          ###   ########.fr       */
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
		ft_error("minishel", "parse error near `\n'", "");
		all->err = 258;
	}
	str = ft_malloc(all->j - i + 1);
	ft_strlcpy(str, &all->str[i], all->j - i + 1);
	all->j--;
	return (str);
}

int	ft_redirect(t_all *all, t_parser *parser)
{
	char	*path;

	path = get_next_word(all);
	parser->redfd[FD_W] = open(path, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (parser->redfd[FD_W] < 0)
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
	parser->redfd[FD_W] = open(path, O_RDWR | O_CREAT | O_APPEND, 0777);
	if (parser->redfd[FD_W] < 0)
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
	parser->redfd[FD_R] = open(path, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (parser->redfd[FD_R] < 0)
	{
		printf("Error");
		return (1);
	}
	return (0);
}

int	ft_redirects(t_all *all, t_parser *parser)
{
	ft_check_to_syntax_error(&all->str[all->j + 1], &all->syntax_error);
	if (all->str[all->j] == '>' && all->str[all->j + 1] == '>')
		ft_double_redirect(all, parser);
	else if (all->str[all->j] == '>')
		ft_redirect(all, parser);
	else if (all->str[all->j] == '<')
		ft_reverse_redirect(all, parser);
	return (0);
}
