/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:02:48 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/06 15:40:09 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_set_env(t_all *all, char **env)
{
	char	**temp;
	int		i;

	i = 0;
	while(env[i])
	{
		temp = ft_split(env[i], '=');
		if (!all->env)
			all->env = ft_dicnew(temp[0], temp[1]);
		else
			ft_dicadd_back(all->env, ft_dicnew(temp[0], temp[1]));
		free(temp);
		i++;
	}
}