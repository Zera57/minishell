/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_double_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:18:46 by larlena           #+#    #+#             */
/*   Updated: 2021/04/14 19:46:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char	*ft_get_value_name(const char *str)
{
	size_t	i;
	char	*dst;

	i = -1;
	while (str[++i] != ' ')
		;
	dst = calloc(sizeof(char), i + 1);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, str, i);
	return (dst);
}

static void	ft_parsing_dollar(t_all *all, t_list *parser, const char *str)
{
	char *buf;
	char *tmp;

	if (str[all->j] == ' ' || str[all->j] == '\0')

	buf = ft_get_value_name(&str[all->j]);
	ft_dic_get_value(all->env, buf);
	tmp = ft_strjoin(((t_parser *)parser->content)->arg[all->ln], buf);
	free(((t_parser *)parser->content)->arg[all->ln]);
	((t_parser *)parser->content)->arg[all->ln] = tmp;
	free(tmp);
	free(buf);
}

void		ft_parsing_double_quotes(t_all *all, t_list *parser, const char *str)
{
	while (str[++all->j] && str[all->j] != '"')
	{
		if (str[all->j] == '\\')
		{
			all->j++;
		}
		if (str[all->j] == '$')
			ft_parsing_dollar(all, parser, str);
	}
}