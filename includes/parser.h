/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:01:48 by larlena           #+#    #+#             */
/*   Updated: 2021/04/12 20:13:14 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include <fcntl.h>



int     ft_redirect(t_all *all);
int     ft_redirect_reverse(t_all *all);
int     ft_redirect_double(t_all *all);
int     ft_pipe(t_all *all);
int     ft_semicolon(t_all *all);
char	*ft_rewrite(char *src, char c);
char	**ft_rewrite_arr(char **arg, size_t size);

#endif