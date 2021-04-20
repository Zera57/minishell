/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:19:03 by larlena           #+#    #+#             */
/*   Updated: 2021/04/20 19:09:05 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_list	*my_lstlast(t_list *lst, t_list *last)
{
	while (lst->next && lst->next != last)
		lst = lst->next;
	return (lst);
}

void	ft_command_execution(t_all *all)
{
	t_list	*buff;
	pid_t	pid[ft_lstsize(all->parser)];
	size_t	i;
	size_t	max;

	i = -1;
	max = (size_t)ft_lstsize(all->parser);
	while (++i < max)
	{
		buff = my_lstlast(all->parser, buff);
		ft_command_search(all, buff);
	}
	ft_clear_parser(all->parser);
}