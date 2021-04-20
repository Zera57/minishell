/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:13:49 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/20 11:40:03 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include <term.h>
# include <errno.h>
# include <termios.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "../Libft/libft.h"
# include "structs.h"
# include "utils.h"
# include "commands.h"
# include "parser.h"

extern int result;

int			ft_analize_string(t_all *all);
void		ft_set_env(t_all *all, char **env);
char		**ft_get_env(t_all *all);
int			ft_type(t_all *all);
int			ft_error(char *command, char *text, char *arg);
int			ft_parser(t_all *all, t_list **parser, const char *str);



#endif