/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:50:23 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/17 13:46:37 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.h"

void	ft_cd(t_all *all, t_parser *parser)
{
	char	pwd[1024];
	char	*apath;

	if (parser->arg[1][0] == '~')
		apath = ft_strjoin(ft_dic_get_value(all->env, "HOME")->value, &parser->arg[1][1]);
	else
		apath = ft_strdup(parser->arg[1]);
	if (chdir(apath) != 0)
	{
		ft_error("minishell: cd:", "No such file or directory", parser->arg[1]);
		all->err = 1;
	}
	else
	{
		getcwd(pwd, 1024);
		free(ft_dic_get_value(all->env, "OLDPWD")->value);
		ft_dic_get_value(all->env, "OLDPWD")->value
		= ft_dic_get_value(all->env, "PWD")->value;
		ft_dic_get_value(all->env, "PWD")->value = ft_strdup(pwd);
	}
	free(apath);
}
