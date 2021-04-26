/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:14:26 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/26 10:52:37 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.h"

void	ft_echo_n(t_parser *parser)
{
	int i;

	i = 2;
	while (parser->arg[i])
	{
		if (i != 2)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(parser->arg[i], 1);
		i++;
	}
}

void	ft_echo(t_all *all, t_parser *parser)
{
	int	i;

	i = 1;
	all->i++;
	if (parser->arg[1] && !ft_strcmp(parser->arg[1], "-n"))
	{
		ft_echo_n(parser);
		exit(0);
	}
	else
		while (parser->arg[i])
		{
			if (i != 1)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(parser->arg[i], 1);
			i++;
		}
	ft_putchar('\n');
}
