/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:28:42 by larlena           #+#    #+#             */
/*   Updated: 2021/05/23 17:29:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_get_value_name(const char *str)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (ft_isdigit(str[i]) || str[i] == '?')
		i++;
	else
	{
		while (ft_isalpha(str[i]) || str[i] == '_')
			i++;
	}
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
	if (ft_isdigit(all->str[all->j]))
		all->j++;
	else
	{
		while (ft_isalnum(all->str[all->j]) || all->str[all->j] == '_')
			all->j++;
	}
	if (tmp == NULL)
	{
		return (1);
	}
	return (0);
}

char 	*ft_dollar_err(t_all *all, t_list *parser, char *buf)
{
	char	*tmp;
	char	*result;

	tmp = ft_itoa(all->err);
	result = ft_strjoin((
				(t_parser *)parser->content)->arg[all->ln], tmp);
	all->j++;
	free(tmp);
	free(buf);
	return (result);
}

void	ft_parsing_dollar(t_all *all, t_list *parser, const char *str)
{
	t_dictionary	*tmp;
	char			*buf;
	char			*result;

	all->j++;
	buf = ft_get_value_name(&str[all->j]);
	if (buf[0] == '?')
		result = ft_dollar_err(all, parser, buf);
	else
	{
		tmp = ft_dic_get_value(all->env, buf);
		if (ft_check_value(all, parser, tmp, buf))
		{
			all->j--;
			return ;
		}
		result = ft_strjoin((
					(t_parser *)parser->content)->arg[all->ln], tmp->value);
	}
	all->j--;
	free(((t_parser *)parser->content)->arg[all->ln]);
	((t_parser *)parser->content)->arg[all->ln] = result;
}
