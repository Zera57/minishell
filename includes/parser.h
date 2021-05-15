/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:01:48 by larlena           #+#    #+#             */
/*   Updated: 2021/05/15 15:51:57 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

# define FD_W 1
# define FD_R 0

int		ft_redirects(t_all *all, t_parser *parser);
int		ft_semicolon(t_all *all, t_list **parser, const char *str);

void	ft_rewrite(char **src, char c);
void	ft_skip_space(const char *str, int *i);
void	ft_clear_parser(t_list *parser);
char	**ft_rewrite_arr(char **arg, size_t size);
int		ft_isspecial_symbols(char c);
void	ft_create_new_list_parser(t_list **parser);
void	ft_initialization_struct_parser(t_all *all, t_list **parser);

void	ft_parsing_double_quotes(t_all *all, t_list *parser, const char *str);
void	ft_parsing_single_quotes(t_all *all, t_list *parser, const char *str);
void	ft_parsing_dollar(t_all *all, t_list *parser, const char *str);
void	ft_parsing_space(t_all *all, t_list *parser, const char *str);
int     ft_parsing_pipe(t_all *all, t_list **parser, const char *str);
void	ft_command_execution(t_all *all);

int		ft_search_commands(t_all *all, t_list *parser);
void	ft_search_fork_commands(t_all *all, t_list *parser, char *command);
int		ft_search_builtin_commands(t_all *all, t_list *parser, char *command);

int		ft_struct_pipe(t_list *parser);
t_list	*ft_search_previous(t_list *begin, t_list *present);

#endif