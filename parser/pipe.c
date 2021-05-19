/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:27:39 by larlena           #+#    #+#             */
/*   Updated: 2021/05/19 14:26:21 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_struct_pipe(t_list *parser)
{
	while (parser)
	{
		if (pipe(((t_parser *)parser->content)->pipefd))
			return (-1);
		parser = parser->next;
	}
	return (0);
}

int	ft_parsing_pipe(t_all *all, t_list **parser, const char *str)
{
	ft_create_new_list_parser(parser);
	ft_skip_space(str, &all->j);
	all->ln = 0;
	return (0);
}
