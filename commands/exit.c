/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:23:10 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/26 17:51:56 by larlena          ###   ########.fr       */
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
		exit((unsigned char)errno);
	while (parser->arg[1][i])
		if (!ft_isdigit(parser->arg[1][i++]))
		{
			ft_error("minishell: exit:", "numeric argument required", "");
			exit((unsigned char)errno);
		}
	i = 0;
	while (parser->arg[i])
		i++;
	if (i > 2)
	{
		ft_error("minishell: exit:", "too many arguments", "");
		return ;
	}
	exit((unsigned char)errno);
}