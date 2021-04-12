/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:48:36 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/08 16:50:18 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_type(t_all *all)
{
	all->str[all->i] = all->buff[0];
	all->i++;
	all->str[all->i] = '\0';
	if (all->history->next == NULL)
	{
		free(all->history->str);
		all->history->str = ft_strdup(all->str);
	}
	write(1, all->buff, 1);
	return (0);
}