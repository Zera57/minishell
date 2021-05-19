/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:19:03 by larlena           #+#    #+#             */
/*   Updated: 2021/05/19 19:47:41 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void 	ft_one_command_execution(t_all *all, pid_t *pid)
{
	ft_fd_red_replacement(all->parser->content);
	if (ft_search_builtin_commands(all, all->parser,
			((t_parser *)all->parser->content)->arg[0]))
	{
		*pid = protected_fork();
		if (*pid == 0)
		{
			ft_search_fork_commands(all, all->parser,
				((t_parser *)all->parser->content)->arg[0]);
			exit (127);
		}
		else
		{
			waitpid(*pid, &all->err, 0);
			all->err = WEXITSTATUS(all->err);
			if (all->err == 127)
				ft_error((((t_parser *)all
							->parser->content)->arg[0]), "command not found");
		}
	}
	ft_fd_red_replacement_back(all->parser->content);
}

void	ft_create_pids(t_all *all, pid_t *pid, t_list *present)
{
	*pid = protected_fork();
	if (*pid == 0)
		ft_search_commands(all, present);
	close(((t_parser *)present->content)->pipefd[FD_W]);
}

void	ft_wait_pids(t_all *all, pid_t *pid, t_list *present)
{
	waitpid(*pid, &all->err, 0);
	close(((t_parser *)present->content)->pipefd[FD_R]);
	all->err = WEXITSTATUS(all->err);
	if (all->err == 127)
		ft_error(((t_parser *)present->content)->arg[0], "command not found");
	if (present->next)
		all->err = 0;
}

void	ft_multi_command_exectuion(t_all *all, pid_t *pid)
{
	size_t	i;
	t_list	*buf;

	i = 0;
	buf = all->parser;
	ft_struct_pipe(all->parser);
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
}

void	ft_command_execution(t_all *all)
{
	pid_t	*pid;

	pid = ft_calloc(sizeof(pid_t), ft_lstsize(all->parser) + 1);
	if (ft_lstsize(all->parser) == 1)
		ft_one_command_execution(all, pid);
	else
		ft_multi_command_exectuion(all, pid);
	ft_clear_parser(all->parser);
	free(pid);
	all->parser = NULL;
}
