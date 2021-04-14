/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:01:48 by larlena           #+#    #+#             */
/*   Updated: 2021/04/14 19:57:07 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>



int		ft_redirects(t_all *all);
int     ft_pipe(t_all *all);
int     ft_semicolon(t_all *all);
char	*ft_rewrite(char *src, char c);
char	**ft_rewrite_arr(char **arg, size_t size);

char	*ft_rewrite(char *src, char c);
char	**ft_rewrite_arr(char **arg, size_t size);
void	ft_create_new_list_parser(t_list **parser);
void	ft_parsing_double_quotes(t_all *all, t_list *parser, const char *str);
void	ft_parsing_single_quotes(t_all *all, t_list *parser, const char *str);
void	ft_parsing_space(t_all *all, t_list *parser, const char *str);

#endif