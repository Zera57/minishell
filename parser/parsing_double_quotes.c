/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_double_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:18:46 by larlena           #+#    #+#             */
/*   Updated: 2021/04/22 17:43:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_parsing_double_quotes(t_all *all, t_list *parser, const char *str)
{
	while (str[++all->j] && str[all->j] != '"')
	{
		if (str[all->j] == '\\')
			all->j++;
		if (str[all->j] == '$')
			ft_parsing_dollar(all, parser, str);
	}
}