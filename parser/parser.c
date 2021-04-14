/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:44:47 by larlena           #+#    #+#             */
/*   Updated: 2021/04/14 19:55:04 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	ft_initialization_struct_parser(t_all *all, t_list **parser)
{
	all->j = -1;
	all->ln = 0;
	ft_create_new_list_parser(parser);
}

int			ft_parser(t_all *all, t_list **parser, const char *str)
{
	ft_initialization_struct_parser(all, parser);
	while (str[++all->j])
	{
		if (str[all->j] == ';')
			ft_semicolon(all);
		if (str[all->j] == '|')
			ft_pipe(all, parser);
		if (str[all->j] == '>')
			;
		if (str[all->j] == '"')
			ft_parsing_double_quotes(all, *parser, str);
		if (str[all->j] == '\'')
			ft_parsing_single_quotes(all, *parser, str);
		if (str[all->j] == ' ')
			ft_parsing_space(all, *parser, str);
		else
			((t_parser *)(*parser)->content)->arg[all->ln] =
			ft_rewrite(((t_parser *)(*parser)->content)->arg[all->ln], str[all->j]);
	}
	ft_command_search(all);
	ft_semicolon(all);
//	ft_free(((t_parser *)(*parser)->content)->arg);
	return (0);
}

// int main(int argc, char **argv, char **env)
// {
//     t_all all;
// 	ft_set_env(&all, env);
//     ft_strlcpy(all.str, "pwd ;", 14);
//     all.str[5] = 0;
// 	ft_parser(&all, &all.parser, all.str);
// 	return (0);
// }
