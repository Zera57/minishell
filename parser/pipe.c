/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:27:39 by larlena           #+#    #+#             */
/*   Updated: 2021/04/20 11:21:06 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_pipe(t_all *all, t_list **parser)
{
	ft_create_new_list_parser(parser);
	all->ln = 0;
	while (all->str[all->j + 1] == ' ')
		all->j++;
	return (0);
}