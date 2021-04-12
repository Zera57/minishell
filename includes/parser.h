/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:01:48 by larlena           #+#    #+#             */
/*   Updated: 2021/04/12 19:23:18 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include <fcntl.h>



int		ft_redirect(t_all *all);
int		ft_redirect_reverse(t_all *all);
int		ft_redirect_double(t_all *all);
int		ft_pipe(t_all *all);
int		ft_semicolon(t_all *all);

#endif