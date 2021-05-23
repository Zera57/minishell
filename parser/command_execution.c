/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:19:03 by larlena           #+#    #+#             */
/*   Updated: 2021/05/23 17:54:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void 	ft_one_command_execution(t_all *all, pid_t *pid)
{
	ft_fd_red_replacement(all->parser->content);
	if (ft_search_builtin_commands(all, all->parser,
			((t_parser *)all->parser->content)->arg[0]))
	{
		ft_create_pid(all, pid, all->parser);
		ft_wait_pid(all, pid, all->parser);
		signal(SIGINT, &f1);
		signal(SIGQUIT, &f2);
	}
	ft_fd_red_replacement_back(all->parser->content);
}

void	ft_multi_command_exectuion(t_all *all, pid_t *pid)
{
	size_t	i;
	t_list	*buf;

	i = 0;
	buf = all->parser;
	ft_struct_pipe(all->parser);
	signal(SIGINT, &f);
	while (buf)
	{
		ft_create_pids(all, &pid[i], buf);
		buf = buf->next;
		i++;
	}
	i = 0;
	buf = all->parser;
	while (buf)
	{
		ft_wait_pids(all, &pid[i], buf);
		buf = buf->next;
		i++;
	}
	signal(SIGINT, &f1);
}

void	ft_command_execution(t_all *all)
{
	pid_t	*pid;

	pid = ft_calloc(sizeof(pid_t), ft_lstsize(all->parser) + 1);
	if (ft_lstsize(all->parser) == 1)
	{
		if (!(((t_parser *)all->parser->content)->redfd[FD_R] < 0)
			&& !(((t_parser *)all->parser->content)->redfd[FD_W] < 0))
			ft_one_command_execution(all, pid);
	}
	else
		ft_multi_command_exectuion(all, pid);
	ft_clear_parser(all->parser);
	free(pid);
	all->parser = NULL;
}
