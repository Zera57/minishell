/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:42:09 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/07 13:25:46 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**sort_by_name(char **env, int numitems)
{
	int		i;
	int		didSwap;
	int		limit;
	char	*temp;

	didSwap = 1;
	limit = numitems - 1;
	while (didSwap)
	{
		didSwap = 0;
		while (i < limit)
		{
			if (ft_strcmp(env[i], env[i + 1]) > 0)
			{
				temp = env[i];
				env[i] = env[i + 1];
				env[i + 1] = temp;
				didSwap = 1;
			}
			i++;
		}
		limit--;
	}
	return (env);
}

void	ft_export(t_all *all)
{
	char	**str;
	int		i;

	while (all->envc[i])
		i++;
	str = sort_by_name(all->envc, i);
	i = 0;
	while (str[i])
		ft_putendl_fd(str[i++], 1);
}
