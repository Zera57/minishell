/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:44:47 by larlena           #+#    #+#             */
/*   Updated: 2021/04/12 13:48:46 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		ft_parser(t_all *all)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	while (all->str[++i])
	{
		if (all->str[i] == ';')
			;
		if (all->str[i] == '<')
			ft_redirect_reverse();
		if (all->str[i] == '>' && all->str[i + 1] == '>')
			ft_redirect_double();
		else if (all->str[i] == '>')
			ft_redirect();
		if (all->str[i] == '|')
			ft_pipe();
	}
}
