/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:57:11 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/20 17:12:38 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"

void	ft_cd(t_all *all, t_parser *parser);
void	ft_pwd(t_all *all);
void	ft_env(t_all *all);
void	ft_echo(t_all *all, t_parser *parser);
void	ft_export(t_all *all);
void	ft_export_add(t_all *all, t_parser *parser);
void	ft_unset(t_all *all, t_parser *parser);
void	ft_exit(t_all *all, t_parser *parser);
int		validate_name(char *str);

#endif