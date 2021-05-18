/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:44:47 by larlena           #+#    #+#             */
/*   Updated: 2021/05/18 14:06:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_check_to_syntax_error_semicolon(const char *str)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while(str[i])
	{
		if (ft_isspecial_symbols(str[i]))
		
		i++;
	}
}

int	ft_parser(t_all *all, t_list **parser, const char *str)
{
	all->j = -1;
//	ft_check_to_syntax_error_semicolon(str);
	ft_initialization_struct_parser(all, parser);
	while (str[++all->j])
	{
		if (str[all->j] == ';')
			ft_semicolon(all, parser, str);
		else if (str[all->j] == '|')
			ft_parsing_pipe(all, parser, str);
		else if (str[all->j] == '>' || str[all->j] == '<')
			ft_redirects(all, (t_parser *)ft_lstlast(*parser)->content);
		else if (str[all->j] == '"')
			ft_parsing_double_quotes(all, ft_lstlast(*parser), str);
		else if (str[all->j] == '\'')
			ft_parsing_single_quotes(all, ft_lstlast(*parser), str);
		else if (str[all->j] == ' ')
			ft_parsing_space(all, ft_lstlast(*parser), str);
		else if (str[all->j] == '$')
			ft_parsing_dollar(all, ft_lstlast(*parser), str);
		else
			ft_rewrite(&((t_parser *)ft_lstlast(*parser)->content)->arg[all->ln], str[all->j]);
	}
	ft_command_execution(all);
	return (0);
}
