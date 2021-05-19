/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:51:25 by larlena           #+#    #+#             */
/*   Updated: 2021/05/19 17:23:50 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_return_error(char *text, char *arg)
{
	all.err = 258;
	ft_error(text, arg);
	return (1);
}

void	ft_skip_space(const char *str, int *i)
{
	while (str[*i + 1] == ' ')
		(*i)++;
}

int	ft_isspecial_symbols(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == ';');
}
