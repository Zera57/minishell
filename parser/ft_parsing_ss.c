/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_ss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:49:01 by larlena           #+#    #+#             */
/*   Updated: 2021/04/13 15:14:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		ft_semicolon(t_all *all)
{
	if (!ft_strncmp(all->parser.arg[0], "pwd", 3))
		ft_pwd(all);
	return (0);
}


int		ft_pipe(t_all *all)
{
	return (0);
}