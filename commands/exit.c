/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:23:10 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/12 15:14:21 by hapryl           ###   ########.fr       */
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
			ft_putendl_fd("numeric argument required", 1);
			exit(errno);
		}
	i = 0;
	while (all->parser.arg[i])
		i++;
	if (i > 1)
	{
		ft_putendl_fd("too many arguments", 1);
		return ;
	}
	exit(errno);
}