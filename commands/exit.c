/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:23:10 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/20 17:04:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_all *all, t_parser *parser)
{
	int	i;

	ft_putendl_fd("exit", 1);
	i = 0;
	while (parser->arg[0][i])
		if (!ft_isdigit(parser->arg[0][i++]))
		{
			ft_error("minishell: exit:", "numeric argument required", "");
			exit(errno);
		}
	i = 0;
	while (parser->arg[i])
		i++;
	if (i > 1)
	{
		ft_error("minishell: exit:", "too many arguments", "");
		return ;
	}
	exit(errno);
}