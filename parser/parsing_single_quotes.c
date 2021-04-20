/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_single_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:26:50 by larlena           #+#    #+#             */
/*   Updated: 2021/04/20 11:21:06 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_parsing_single_quotes(t_all *all, t_list *parser, const char *str)
{
	while (str[++all->j] && str[all->j] != '\'')
	{
		((t_parser *)parser->content)->arg[all->ln] =
		ft_rewrite(((t_parser *)parser->content)->arg[all->ln], str[all->j]);
	}
}