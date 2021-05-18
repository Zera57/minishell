/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:19:03 by larlena           #+#    #+#             */
/*   Updated: 2021/05/18 16:52:46 by larlena          ###   ########.fr       */
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

void	ft_fd_red_replacement(t_parser *parser)
{
	if (parser->redfd[FD_W])
		dup2(parser->redfd[FD_W], FD_W);
	if (parser->redfd[FD_R])
		dup2(parser->redfd[FD_R], FD_R);
}

void 	ft_one_command_execution(t_all *all, pid_t *pid)
{
	int		fd_w;
	int		fd_r;
	
	fd_w = dup(FD_W);
	fd_r = dup(FD_R);
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
				ft_error("ASSZATshell", (((t_parser *)all->parser->content)->arg[0]), "command not found");
		}
	}
	dup2(fd_w, FD_W);
	dup2(fd_r, FD_R);
	close(fd_w);
	close(fd_r);
}

void	ft_multi_command_exectuion(t_all *all, pid_t *pid)
{
	size_t	i;
	t_list	*buf;

	i = -1;
	buf = all->parser;
	ft_struct_pipe(all->parser);
	while (buf)               
	{
		pid[++i] = protected_fork();
		if (pid[i] == 0)
			ft_search_commands(all, buf);
		close(((t_parser *)buf->content)->pipefd[FD_W]);
		buf = buf->next;
	}
	i = -1;
	buf = all->parser;
	while (buf)
	{
		waitpid(pid[++i], &all->err, 0);
		close(((t_parser *)buf->content)->pipefd[FD_R]);
		all->err = WEXITSTATUS(all->err);
		if (all->err == 127)
			ft_error("ASSZATshell", ((t_parser *)buf->content)->arg[0], "command not found");
		if (buf->next)
			all->err = 0;
		buf = buf->next;
	}
}

void	ft_command_execution(t_all *all)
{
	pid_t	*pid;

	pid = ft_calloc(sizeof(pid_t), ft_lstsize(all->parser) + 1);
	if (!all->syntax_error)
	{
		if (ft_lstsize(all->parser) == 1)
			ft_one_command_execution(all, pid);
		else
			ft_multi_command_exectuion(all, pid);
	}
	else
		ft_error("ASSZATshell", "syntax error", "");
	ft_clear_parser(all->parser);
	free(pid);
	all->parser = NULL;
}
