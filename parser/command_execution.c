/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:19:03 by larlena           #+#    #+#             */
/*   Updated: 2021/04/26 15:38:46 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static pid_t	ft_protected_fork(void)
{
	pid_t	buf;

	buf = fork();
	if (buf == -1)
		exit(0);
	return (buf);
}

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
	if (max == 1)
	{
		if (!ft_search_builtin_commands(all, all->parser, ((t_parser *)all->parser->content)->arg[0]))
		{
			ft_clear_parser(all->parser);
			return ;	
		}
		pid[0] = ft_protected_fork();
		if (pid[0] == 0)
		{
			ft_search_fork_commands(all, all->parser, ((t_parser *)all->parser->content)->arg[0]);
			exit (0);
		}
		else
			waitpid(pid[0], &status, 0);
	}
	else
	{
		while (++i < max)
		{
			buff = my_lstlast(all->parser, buff);
			pid[i] = ft_protected_fork();
			while (pid[i] == 0)
				ft_search_commands(all, buff);
		}
		i = -1;
		while (++i < max)
			waitpid(pid[i], &status, 0);
	}
	ft_clear_parser(all->parser);
}
