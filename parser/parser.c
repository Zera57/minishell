/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:44:47 by larlena           #+#    #+#             */
/*   Updated: 2021/04/12 20:06:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		ft_parser(t_all *all, t_parser *parser, const char *str)
{
	size_t	ac;

	i = -1;
	ac = 0;
	while (str[++i])
	{
		if (str[i] == '>')
//		if (str[i] == "\"")
//			ft_parsing_double_quotes(all, &arg[ac], str, &i);
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			ac++;
			arg = ft_rewrite_arr(&arg, ac);
		}
		else
			arg[ac] =ft_rewrite(&arg[ac], str[i]);
	}
}
