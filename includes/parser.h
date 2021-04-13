/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:01:48 by larlena           #+#    #+#             */
/*   Updated: 2021/04/13 15:20:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include <fcntl.h>



int		ft_redirects(t_all *all);
int     ft_pipe(t_all *all);
int     ft_semicolon(t_all *all);
char	*ft_rewrite(char *src, char c);
char	**ft_rewrite_arr(char **arg, size_t size);

char	*ft_rewrite(char *src, char c);
char	**ft_rewrite_arr(char **arg, size_t size);
void	ft_parsing_double_quotes(t_all *all, t_parser *parser, const char *str);

#endif