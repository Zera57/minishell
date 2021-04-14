/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_ss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:49:01 by larlena           #+#    #+#             */
/*   Updated: 2021/04/14 19:50:06 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		ft_semicolon(t_all *all)
{
	if (!ft_strncmp(all->parser.arg[0], "pwd", 3))
		ft_pwd(all);
	return (0);
}
