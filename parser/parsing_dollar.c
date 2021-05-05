/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:28:42 by larlena           #+#    #+#             */
/*   Updated: 2021/04/28 14:27:40 by larlena          ###   ########.fr       */
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

static int	ft_check_value(t_all *all, t_list *parser,
				t_dictionary *tmp, char *buf)
{
	if (*buf == '\0')
	{
		ft_rewrite(&((t_parser *)parser->content)->arg[all->ln], '$');
		free(buf);
		return (1);
	}
	free(buf);
	while (ft_isalnum(all->str[all->j]) || all->str[all->j] == '_')
		all->j++;
	if (tmp == NULL)
	{
		return (1);
	}
	return (0);
}

void	ft_parsing_dollar(t_all *all, t_list *parser, const char *str)
{
	t_dictionary	*tmp;
	char			*buf;

	all->j++;
	buf = ft_get_value_name(&str[all->j]);
	tmp = ft_dic_get_value(all->env, buf);
	if (ft_check_value(all, parser, tmp, buf))
		return ;
	buf = ft_strjoin(((t_parser *)parser->content)->arg[all->ln], tmp->value);
	free(((t_parser *)parser->content)->arg[all->ln]);
	((t_parser *)parser->content)->arg[all->ln] = buf;
}
