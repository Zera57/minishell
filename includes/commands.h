/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:57:11 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/13 13:48:37 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"

void	ft_cd(t_all *all);
void	ft_pwd(t_all *all);
void	ft_env(t_all *all);
void	ft_echo(t_all *all);
void	ft_export(t_all *all);
void	ft_export_add(t_all *all);
void	ft_unset(t_all *all);
void	ft_exit(t_all *all);
int		validate_name(char *str);

#endif