/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:23:10 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/13 13:22:15 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_all *all)
{
	int	i;

	ft_putendl_fd("exit", 1);
	i = 0;
	while (all->parser.arg[0][i])
		if (!ft_isdigit(all->parser.arg[0][i++]))
		{
			ft_error("minishell: exit:", "numeric argument required", "");
			exit(errno);
		}
	i = 0;
	while (all->parser.arg[i])
		i++;
	if (i > 1)
	{
		ft_error("minishell: exit:", "too many arguments", "");
		return ;
	}
	exit(errno);
}