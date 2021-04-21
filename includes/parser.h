/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:01:48 by larlena           #+#    #+#             */
/*   Updated: 2021/04/21 18:12:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

int		ft_redirects(t_all *all, t_parser *parser);
int		ft_semicolon(t_all *all, t_list **parser, const char *str);

char	*ft_rewrite(char *src, char c);
void	ft_clear_parser(t_list *parser);
char	**ft_rewrite_arr(char **arg, size_t size);
void	ft_create_new_list_parser(t_list **parser);
void	ft_initialization_struct_parser(t_all *all, t_list **parser);

void	ft_parsing_double_quotes(t_all *all, t_list *parser, const char *str);
void	ft_parsing_single_quotes(t_all *all, t_list *parser, const char *str);
void	ft_parsing_space(t_all *all, t_list *parser, const char *str);
int     ft_parsing_pipe(t_all *all, t_list **parser);
void	ft_command_execution(t_all *all);
int		ft_command_search(t_all *all, t_list *parser);

#endif