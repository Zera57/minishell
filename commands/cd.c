/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:50:23 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/13 13:43:23 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.h"

void	ft_cd(t_all *all)
{
	char	*apath;

	if (all->parser.arg[1][0] == '~')
		apath = ft_strjoin(ft_dic_get_value(all->env, "HOME")->value, &all->parser.arg[1][1]);
	else
		apath = all->parser.arg[1];
	free(ft_dic_get_value(all->env, "OLDPWD")->value);
	ft_dic_get_value(all->env, "OLDPWD")->value
	= ft_dic_get_value(all->env, "PWD")->value;
	ft_dic_get_value(all->env, "PWD")->value = apath;
	if (chdir(apath) != 0)
	{
		ft_error("minishell: cd:", "No such file or directory", all->parser.arg[1]);
	}
	printf("Changed directory %s\n", apath);
	return ;
}
