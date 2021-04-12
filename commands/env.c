/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:08:55 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/08 17:16:39 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_all *all)
{
	t_dictionary	*dic;

	dic = all->env;
	while (dic)
	{
		if (dic->value != NULL)
		{
			ft_putstr_fd(dic->key, 1);
			ft_putchar_fd('=', 1);
			ft_putendl_fd(dic->value, 1);
		}
		dic = dic->next;
	}
}
