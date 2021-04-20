/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:08:55 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/20 19:16:26 by larlena          ###   ########.fr       */
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
	exit(0);
}
