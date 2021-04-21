/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:19:03 by larlena           #+#    #+#             */
/*   Updated: 2021/04/21 18:36:00 by larlena          ###   ########.fr       */
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
	size_t	max;
	size_t	i;
	pid_t	pid[ft_lstsize(all->parser)];
	int		status;

	i = -1;
	max = (size_t)ft_lstsize(all->parser);
	while (++i < max)
	{
		buff = my_lstlast(all->parser, buff);
		pid[i] = fork();
		if (pid[i] == -1)
			exit(0);
		while (pid[i] == 0)
			ft_command_search(all, buff);
	}
	i = -1;
	while (++i < max)
		waitpid(pid[i], &status, 0);
	ft_clear_parser(all->parser);
}
