/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:25:05 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/17 13:27:29 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(t_all *all, t_parser *parser)
{
	int	i;

	i = 1;
	while (parser->arg[i])
	{
		if (!validate_name(parser->arg[i]))
		{
			err = 1;
			ft_error("minishell unset:", "not a valid identifier:", parser->arg[i]);
		}
		else
			all->env = ft_dic_delete(all->env, parser->arg[i]);
		i++;
	}
}