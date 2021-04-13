/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:14:26 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/13 13:34:04 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.h"

void	ft_echo(t_all *all)
{
	int	i;

	i = 2;
	if (!ft_strchr(all->parser.arg[1], 'n'))
		while (all->parser.arg[i])
		{
			ft_putendl_fd(all->parser.arg[i], 1);
			i++;
		}
	else
		while (all->parser.arg[i])
		{
			if (i != 2)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(all->parser.arg[i], 1);
			i++;
		}
}
