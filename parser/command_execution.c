/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:19:03 by larlena           #+#    #+#             */
/*   Updated: 2021/05/06 15:18:51 by larlena          ###   ########.fr       */
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

void 	ft_one_command_execution(t_all *all, pid_t *pid)
{
	if (ft_search_builtin_commands(all, all->parser, ((t_parser *)all->parser->content)->arg[0]))
	{
		*pid = protected_fork();
		if (*pid == 0)
		{
			ft_search_fork_commands(all, all->parser, ((t_parser *)all->parser->content)->arg[0]);
			exit (0);
		}
		else
			waitpid(*pid, &err, 0);
	}
}

void	ft_multi_command_exectuion(t_all *all, pid_t *pid)
{
	size_t	i;
	t_list	*buf;

	i = -1;
	buf = all->parser;
	all->dupfdr = dup(FD_R);
	all->dupfdw = dup(FD_W);
	ft_struct_pipe(all->parser);
	while (buf)
	{
		pid[++i] = protected_fork();

		if (pid[i] == 0)
			ft_search_commands(all, buf);
		buf = buf->next;
	}
	i = -1;
	buf = all->parser;
	while (buf)
	{
		waitpid(pid[++i], &err, 0);
		buf = buf->next;
	}
}

void	ft_command_execution(t_all *all)
{
	pid_t	pid[ft_lstsize(all->parser)];

	if (ft_lstsize(all->parser) == 1)
		ft_one_command_execution(all, pid);
	else
		ft_multi_command_exectuion(all, pid);
	ft_clear_parser(all->parser);
	all->parser = NULL;
}
