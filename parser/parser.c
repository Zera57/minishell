/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:44:47 by larlena           #+#    #+#             */
/*   Updated: 2021/04/13 15:17:11 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		ft_parser(t_all *all, t_parser *parser, const char *str)
{
	size_t	ac;

	parser->i = -1;
	parser->ln = 0;
	parser->arg = calloc(sizeof(char *), 2);
	parser->arg[0] = calloc(sizeof(char), 1);
	while (str[++parser->i])
	{
		if (str[parser->i] == ';')
			ft_semicolon(all);
		if (str[parser->i] == '"')
			ft_parsing_double_quotes(all, parser, str);
		if (str[parser->i] == ' ')
		{
			while (str[parser->i + 1] == ' ')
				parser->i++;
			parser->ln++;
			parser->arg = ft_rewrite_arr(parser->arg, parser->ln);
		}
		else
			parser->arg[parser->ln] = ft_rewrite(parser->arg[parser->ln], str[parser->i]);
	}
	ft_semicolon(all);
	ft_free(parser->arg);
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
