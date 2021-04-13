/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:25:05 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/12 15:14:21 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(t_all *all)
{
	int	i;

	i = 0;
	while (all->parser.arg[i])
	{
		all->env = ft_dic_delete(all->env, all->parser.arg[i]);
		i++;
	}
	ft_array_free(all->parser.arg, i);
}