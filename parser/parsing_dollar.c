/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:28:42 by larlena           #+#    #+#             */
/*   Updated: 2021/05/06 13:48:56 by hapryl           ###   ########.fr       */
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
	dst[i] = 0;
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

static char	*ft_dollar_errno(t_all *all, char *buf)
{
	char	*result;
	char	*err;

	err = ft_itoa(errno);
	result = ft_strjoin(err, &buf[1]);
	free(err);
	free(buf);
	all->j += ft_strlen(result);
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
		result = ft_dollar_errno(all, buf);
	else
	{
		tmp = ft_dic_get_value(all->env, buf);
		if (ft_check_value(all, parser, tmp, buf))
			return ;
		result = ft_strjoin((
			(t_parser *)parser->content)->arg[all->ln], tmp->value);
	}
	free(((t_parser *)parser->content)->arg[all->ln]);
	((t_parser *)parser->content)->arg[all->ln] = result;
}
