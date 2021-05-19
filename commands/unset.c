/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:25:05 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 16:08:41 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	validate_name(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		all.err = 1;
		return (ft_error("export", "not an identifier", str));
	}
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			all.err = 1;
			return (ft_error("export", "not an identifier", str));
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
			ft_error("minishell unset:", "not a valid identifier:",
				 parser->arg[i]);
		}
		else
			all->env = ft_dic_delete(all->env, parser->arg[i]);
		i++;
	}
}
