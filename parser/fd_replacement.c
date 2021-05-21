/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_replacement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:23:08 by larlena           #+#    #+#             */
/*   Updated: 2021/05/21 19:32:19 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_fd_red_replacement(t_parser *parser)
{
	parser->buf[FD_W] = dup(FD_W);
	parser->buf[FD_R] = dup(FD_R);
	if (parser->redfd[FD_W])
		dup2(parser->redfd[FD_W], FD_W);
	if (parser->redfd[FD_R])
		dup2(parser->redfd[FD_R], FD_R);
}

void	ft_fd_red_replacement_back(t_parser *parser)
{
	dup2(parser->buf[FD_W], FD_W);
	dup2(parser->buf[FD_R], FD_R);
	close(parser->buf[FD_W]);
	close(parser->buf[FD_R]);
}

void	ft_fd_replacement_first_elem(t_list *present)
{
	if (((t_parser *)present->content)->redfd[FD_R])
		dup2(((t_parser *)present->content)->redfd[FD_R], FD_R);
	if (((t_parser *)present->content)->redfd[FD_W])
		dup2(((t_parser *)present->content)->redfd[FD_W], FD_W);
	else
		dup2(((t_parser *)present->content)->pipefd[FD_W], FD_W);
}

void	ft_fd_replacement_middle_elem(t_list *previous, t_list *present)
{
	if (((t_parser *)present->content)->redfd[FD_R])
		dup2(((t_parser *)present->content)->redfd[FD_R], FD_R);
	else
		dup2(((t_parser *)previous->content)->pipefd[FD_R], FD_R);
	if (((t_parser *)present->content)->redfd[FD_W])
		dup2(((t_parser *)present->content)->redfd[FD_W], FD_W);
	else
		dup2(((t_parser *)present->content)->pipefd[FD_W], FD_W);
}

void	ft_fd_replacement_last_elem(t_list *previous, t_list *present)
{
	if (((t_parser *)present->content)->redfd[FD_W])
		dup2(((t_parser *)present->content)->redfd[FD_W], FD_W);
	if (((t_parser *)present->content)->redfd[FD_R])
		dup2(((t_parser *)present->content)->redfd[FD_R], FD_R);
	else
		dup2(((t_parser *)previous->content)->pipefd[FD_R], FD_R);
}
