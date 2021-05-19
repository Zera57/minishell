/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_double_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:18:46 by larlena           #+#    #+#             */
/*   Updated: 2021/05/19 10:34:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_isspecial_symbol_for_double_quotes(char first, char second)
{
	return (first == '\\' && (second == '"' || second == '$' || second == '\\'));
}

int	ft_parsing_shielding(t_all *all, t_list *parser, const char *str)
{
	if (str[all->j] == '\\')
		all->j++;
	if (str[all->j] == ' ')
	{
		all->syntax_error += 1;
		return (1);
	}
	ft_rewrite(&((t_parser *)parser->content)->arg[all->ln], str[all->j]);
	return (0);
}

void	ft_parsing_double_quotes(t_all *all, t_list *parser, const char *str)
{
	while (str[++all->j] && str[all->j] != '"')
	{
		if (ft_isspecial_symbol_for_double_quotes(str[all->j], str[all->j + 1]))
			ft_parsing_shielding(all, parser, str);
		else if (str[all->j] == '$')
			ft_parsing_dollar(all, parser, str);
		else
			ft_rewrite(&((t_parser *)
					parser->content)->arg[all->ln], str[all->j]);
	}
	if (str[all->j] == '\0')
	{
		all->syntax_error += 1;
		ft_error("ASSZATshell", "sintax error", "double quotes must be closed");
		all->err = 258;
	}
}
