/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:43:21 by larlena           #+#    #+#             */
/*   Updated: 2021/05/23 17:57:10 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_exit_status(int status)
{
	if (WIFEXITED(status))
		g_all.err = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_all.err = WTERMSIG(status) + 128;
}

void	ft_create_pid(t_all *all, pid_t *pid, t_list *present)
{
	signal(SIGINT, &f);
	*pid = protected_fork();
	if (*pid == 0)
	{
		signal(SIGINT, &f1);
		ft_search_fork_commands(all, present,
			((t_parser *)present->content)->arg[0]);
		exit (127);
	}
}

void	ft_wait_pid(t_all *all, pid_t *pid, t_list *present)
{
	if (*pid)
	{
		if (!ft_strcmp(((t_parser *)present->content)->arg[0], "minishell"))
			signal(SIGQUIT, &f);
		waitpid(*pid, &all->err, 0);
		check_exit_status(all->err);
		if (all->err == 127)
			ft_error((((t_parser *)present
						->content)->arg[0]), "command not found");
	}
}

void	ft_create_pids(t_all *all, pid_t *pid, t_list *present)
{
	*pid = protected_fork();
	if (*pid == 0)
	{
		signal(SIGINT, &f1);
		ft_search_commands(all, present);
	}
	close(((t_parser *)present->content)->pipefd[FD_W]);
}

void	ft_wait_pids(t_all *all, pid_t *pid, t_list *present)
{
	waitpid(*pid, &all->err, 0);
	close(((t_parser *)present->content)->pipefd[FD_R]);
	check_exit_status(all->err);
	if (all->err == 127)
		ft_error(((t_parser *)present->content)->arg[0], "command not found");
	if (present->next)
		all->err = 0;
}
