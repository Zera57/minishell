/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:25:05 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/13 13:52:40 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(t_all *all)
{
	int	i;

	i = 0;
	while (all->parser.arg[i])
	{
		if (validate_name(all->parser.arg[i]))
			ft_error("minishell unset:", "not a valid identifier:", all->parser.arg[i]);
		else
			all->env = ft_dic_delete(all->env, all->parser.arg[i]);
		i++;
	}
}