/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:44:47 by larlena           #+#    #+#             */
/*   Updated: 2021/04/26 17:30:11 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_parser(t_all *all, t_list **parser, const char *str)
{
	all->j = -1;
	ft_initialization_struct_parser(all, parser);
	while (str[++all->j])
	{
		if (str[all->j] == ';')
			ft_semicolon(all, parser, str);
		else if (str[all->j] == '|')
			ft_parsing_pipe(all, parser);
		else if (str[all->j] == '>' || str[all->j] == '<')
			ft_redirects(all, ((t_parser *)(*parser)->content));
		else if (str[all->j] == '"')
			ft_parsing_double_quotes(all, *parser, str);
		else if (str[all->j] == '\'')
			ft_parsing_single_quotes(all, *parser, str);
		else if (str[all->j] == ' ')
			ft_parsing_space(all, *parser, str);
		else if (str[all->j] == '$')
			ft_parsing_dollar(all, *parser, str);
		else
			ft_rewrite(&((t_parser *)(*parser)->content)->arg[all->ln], str[all->j]);
	}
	ft_command_execution(all);
	return (0);
}
