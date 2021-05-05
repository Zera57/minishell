/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:19:03 by larlena           #+#    #+#             */
/*   Updated: 2021/05/05 16:17:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static pid_t	protected_fork(void)
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

void 	ft_one_command_execution(t_all *all, pid_t *pid)
{
	if (ft_search_builtin_commands(all, all->parser, ((t_parser *)all->parser->content)->arg[0]))
	{
		*pid = ft_protected_fork();
		if (*pid == 0)
		{
			ft_search_fork_commands(all, all->parser, ((t_parser *)all->parser->content)->arg[0]);
			exit (0);
		}
		else
			waitpid(*pid, &err, 0);
	}
}

void	ft_multi_command_exectuion(t_all *all, pid_t *pid, size_t max)
{
	size_t	i;
	t_list	*buff;

	i = -1;
	ft_minishell_pipe(all->parser);
	while (++i < max)
	{
		buff = my_lstlast(all->parser, buff);
		pid[i] = protected_fork();
		while (pid[i] == 0)
			ft_search_commands(all, buff);
	}
	i = -1;
	while (++i < max)
		waitpid(pid[i], &err, 0);
}

void	ft_command_execution(t_all *all)
{
	size_t	max;
	pid_t	pid[ft_lstsize(all->parser)];

	max = (size_t)ft_lstsize(all->parser);
	if (max == 1)
		ft_one_command_execution(all, pid);
	else
		ft_multi_command_exectuion(all, pid, max);
	ft_clear_parser(all->parser);
}
