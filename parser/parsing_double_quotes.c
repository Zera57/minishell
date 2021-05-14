/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_double_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:18:46 by larlena           #+#    #+#             */
/*   Updated: 2021/05/14 17:00:29 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_parsing_double_quotes(t_all *all, t_list *parser, const char *str)
{
	while (str[++all->j] && str[all->j] != '"')
	{
		if (str[all->j] == '\\')
			all->j++;
		else if (str[all->j] == '$')
			ft_parsing_dollar(all, parser, str);
		else
			ft_rewrite(&((t_parser *)(parser)->content)->arg[all->ln], str[all->j]);
	}
	if (str[all->j] == '\0')
	{
		ft_error("minishell", "sintax error", "double quotes must be closed");
		err = 258;
	}
}
