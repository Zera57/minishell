/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:23:10 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/17 14:04:09 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_all *all, t_parser *parser)
{
	int	i;

	all->i++;
	ft_putendl_fd("exit", 1);
	i = 0;
	if (!parser->arg[1])
		exit((unsigned char)all->err);
	while (parser->arg[1][i])
		if (!ft_isdigit(parser->arg[1][i++]))
		{
			ft_error("minishell: exit:", "numeric argument required", "");
			exit(255);
		}
	i = 0;
	while (parser->arg[i])
		i++;
	if (i > 2)
	{
		ft_error("minishell: exit:", "too many arguments", "");
		return ;
	}
	all->err = ft_atoi(parser->arg[1]);
	exit(all->err);
}