/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:28:42 by larlena           #+#    #+#             */
/*   Updated: 2021/04/22 18:12:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_get_value_name(const char *str)
{
	size_t	i;
	char	*dst;

	i = 0;
	while (str[i] != ' ' && str[i] != '"' && str[i])
		i++;
	dst = calloc(sizeof(char), i + 1);
	ft_memcpy(dst, str, i);
	return (dst);
}

void		ft_parsing_dollar(t_all *all, t_list *parser, const char *str)
{
	t_dictionary	*tmp;
	char			*buf;

	if (str[++all->j] == '"' || !str[all->j])
		return ;
	buf = ft_get_value_name(&str[all->j]);
	tmp = ft_dic_get_value(all->env, buf);
	free(buf);
	if (tmp == NULL)
		return ;
	buf = ft_strjoin(((t_parser *)parser->content)->arg[all->ln], tmp->value);
	free(((t_parser *)parser->content)->arg[all->ln]);
	((t_parser *)parser->content)->arg[all->ln] = buf;
	free(tmp);
}
