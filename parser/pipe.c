/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:27:39 by larlena           #+#    #+#             */
/*   Updated: 2021/05/05 17:32:32 by larlena          ###   ########.fr       */
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

int	ft_parsing_pipe(t_all *all, t_list **parser)
{
	ft_create_new_list_parser(parser);
	all->ln = 0;
	while (all->str[all->j + 1] == ' ')
		all->j++;
	return (0);
}
