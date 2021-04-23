/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:23:10 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/23 14:41:06 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_all *all, t_parser *parser)
{
	int	i;

	all->i++;
	ft_putendl_fd("exit", 1);
	i = 0;
	while (parser->arg[1][i])
		if (!ft_isdigit(parser->arg[1][i++]))
		{
			ft_error("minishell: exit:", "numeric argument required", "");
			exit(errno);
		}
	i = 0;
	while (parser->arg[i])
		i++;
	if (i > 2)
	{
		ft_error("minishell: exit:", "too many arguments", "");
		return ;
	}
	exit(errno);
}