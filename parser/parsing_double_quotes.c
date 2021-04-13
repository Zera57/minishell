/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_double_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:18:46 by larlena           #+#    #+#             */
/*   Updated: 2021/04/13 14:13:16 by larlena          ###   ########.fr       */
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

static void	ft_parsing_dollar(t_all *all, t_parser *parser, const char *str)
{
	char *buf;
	char *tmp;

	buf = ft_get_value_name(&str[parser->i]);
	ft_dic_get_value(all->env, buf);
	tmp = ft_strjoin(parser->arg[parser->ln], buf);
	free(parser->arg[parser->ln]);
	parser->arg[parser->ln] = tmp;
	free(tmp);
	free(buf);
}

void		ft_parsing_double_quotes(t_all *all, t_parser *parser, const char *str)
{
	while (str[++parser->i] && str[parser->i] != '"')
	{
		if (str[parser->i] == '\\')
		{
			parser->i++;
		}
		if (str[parser->i] == '$')
			ft_parsing_dollar(all, parser, str);
	}
}