/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:27:39 by larlena           #+#    #+#             */
/*   Updated: 2021/05/05 15:53:27 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	protected_pipe(int pipefd[2])
{
	if(pipe(pipefd))
		exit (0);
}

int	ft_minishell_pipe(t_list *parser)
{
	protected_pipe(((t_parser *)parser->content)->pipefd);
	dup2(((t_parser *)parser->content)->pipefd[FD_W], FD_W);
	dup2(((t_parser *)parser->content)->pipefd[FD_R], FD_R);
	while (parser->next)
	{
		protected_pipe(((t_parser *)parser->next->content)->pipefd);
		dup2(((t_parser *)parser->next->content)->pipefd[FD_R], ((t_parser *)parser->content)->pipefd[FD_R]);
		parser = parser->next;
	}
	return (0);
}

int	ft_parsing_pipe(t_all *all, t_list **parser)
{
	ft_create_new_list_parser(parser);
	all->ln = 0;
	while (all->str[all->j + 1] == ' ')
		all->j++;
	return (0);
}
