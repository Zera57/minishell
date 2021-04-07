/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:57:11 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/07 12:34:15 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"

void	ft_cd(t_all *all, char *path);
void	ft_pwd(t_all *all);
void	ft_env(t_all *all);
void	ft_echo(t_all *all, char *str);
void	ft_export(t_all *all);

#endif