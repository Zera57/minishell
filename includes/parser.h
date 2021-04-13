/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:01:48 by larlena           #+#    #+#             */
/*   Updated: 2021/04/12 20:58:36 by hapryl           ###   ########.fr       */
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

#endif