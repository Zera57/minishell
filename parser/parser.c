/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:44:47 by larlena           #+#    #+#             */
/*   Updated: 2021/05/18 14:44:27 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_return_error(char *command, char *text, char *arg)
{
	ft_error(command, text, arg);
	return (1);
}

int	ft_check_to_syntax_error_semicolon(const char *str)
{
	size_t	i;
	size_t	flag;

	i = 0;
	flag = 0;
	while(str[i])
	{
		if (ft_isspecial_symbols(str[i]))
		{
			if (flag)
				return (ft_return_error("ASSZATshell", "syntax shell", ""));
			flag = i;
		}
		else if (str[i] != ' ')
			flag = 0;
		i++;
	}
	if (ft_isspecial_symbols(str[flag]) && str[flag] != ';')
		return (ft_return_error("ASSZATshell", "syntax shell", ""));
	return (0);
}

int	ft_parsing_special_symbol(t_all *all, t_list **parser, const char *str)
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
	return (0);
}

int	ft_parser(t_all *all, t_list **parser, const char *str)
{
	all->j = -1;
	if (!ft_check_to_syntax_error_semicolon(str))
	{
		ft_initialization_struct_parser(all, parser);
		while (str[++all->j])
			ft_parsing_special_symbol(all, parser, str);
		ft_command_execution(all);
	}
	return (0);
}
