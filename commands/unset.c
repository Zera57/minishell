/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:25:05 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/08 13:42:52 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(t_all *all)
{
	int	i;

	i = 0;
	while (all->arg[i])
	{
		all->env = ft_dic_delete(all->env, all->arg[i]);
		i++;
	}
	ft_array_free(all->arg, i);
}