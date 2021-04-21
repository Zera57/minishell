/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:27:39 by larlena           #+#    #+#             */
/*   Updated: 2021/04/21 18:36:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int		my_pipe(t_all *all)
// {
// 	int	pipefd[2];

// 	pipefd[0] = 
// 	pipefd[1] = 
// }

int		ft_parsing_pipe(t_all *all, t_list **parser)
{
	ft_create_new_list_parser(parser);
	all->ln = 0;
	while (all->str[all->j + 1] == ' ')
		all->j++;
	return (0);
}