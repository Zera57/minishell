/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:14:26 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 14:22:25 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.h"

static int	ft_checkflag(char *flag)
{
	int	i;

	i = 0;
	if (flag[i++] != '-')
		return (1);
	i = 0;
	while (flag[++i] != 0)
		if (flag[i] != 'n')
			return (1);
	return (0);
}

static int	ft_getflag(t_parser *parser)
{
	int	i;

	i = 0;
	while (parser->arg[++i])
	{
		if (ft_checkflag(parser->arg[i]))
			return (--i);
	}
	return (0);
}

void	ft_echo(t_all *all, t_parser *parser)
{
	int	i;
	int	flag;

	i = ft_getflag(parser);
	flag = 0;
	if (i == 0)
		flag = 1;
	while (parser->arg[++i])
	{
		if (i != ft_getflag(parser) + 1)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(parser->arg[i], 1);
	}
	if (flag == 1)
		ft_putchar('\n');
	all->err = 0;
}
