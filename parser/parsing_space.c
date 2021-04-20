/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:33:29 by larlena           #+#    #+#             */
/*   Updated: 2021/04/20 11:21:06 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_parsing_space(t_all *all, t_list *parser, const char *str)
{
	while (str[all->j + 1] == ' ')
		all->j++;
	all->ln++;
	((t_parser *)parser->content)->arg =
	ft_rewrite_arr(((t_parser *)parser->content)->arg, all->ln);
}