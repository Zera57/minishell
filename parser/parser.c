/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:44:47 by larlena           #+#    #+#             */
/*   Updated: 2021/04/06 18:51:04 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		ft_skip_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

int		ft_check_comand(t_all *all, char *str)
{
	size_t	i;
	size_t	cmd;
	int		f;

	i = ft_skip_space(str);
	cmd = 0;
	while (!f)
	{
		f = ft_strncmp(&str[i], all->);
		cmd++;
	}
	
}

int		ft_parser(t_all *all)
{
	size_t	i;

	i = -1;
	while (all->str[++i])
	{
		ft_check_comand(all, &all->str[i]);
	}
}
