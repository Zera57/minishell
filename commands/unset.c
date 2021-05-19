/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:25:05 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 20:49:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	validate_name(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		g_all.err = 1;
		return (ft_error("not an identifier", str));
	}
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			g_all.err = 1;
			return (ft_error("not an identifier", str));
		}
		i++;
	}
	return (1);
}

void	ft_unset(t_all *all, t_parser *parser)
{
	int	i;

	i = 1;
	all->err = 0;
	while (parser->arg[i])
	{
		if (!validate_name(parser->arg[i]))
		{
			all->err = 1;
			ft_error("not a valid identifier:", parser->arg[i]);
		}
		else
			all->env = ft_dic_delete(all->env, parser->arg[i]);
		i++;
	}
}
