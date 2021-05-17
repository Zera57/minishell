/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:14:26 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/17 18:13:50 by hapryl           ###   ########.fr       */
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

static int	ft_flag(char *flag)
{
	int i;

	i = 0;
	if (flag[i++] != '-')
		return (1);
	i = 0;
	while (flag[++i] != 0)
		if (flag[i] != 'n')
			return (1);
	return (0);
}

void	ft_echo(t_all *all, t_parser *parser)
{
	int	i;

	i = 1;
	if (parser->arg[1] && !ft_flag(parser->arg[1]))
		ft_echo_n(parser);
	else
	{
		while (parser->arg[i])
		{
			if (i != 1)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(parser->arg[i], 1);
			i++;
		}
		ft_putchar('\n');
	}
	all->err = 0;
}
