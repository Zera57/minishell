/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:50:23 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 17:27:02 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.h"

static char	*ft_get_apath(t_all *all, t_parser *parser)
{
	char	*apath;

	if (ft_dic_get_value(all->env, "HOME") == NULL)
	{
		ft_error("No such file or directory", "");
		all->err = 1;
		return (NULL);
	}
	else if (parser->arg[1] == NULL)
		apath = ft_strdup(ft_dic_get_value(all->env, "HOME")->value);
	else if (parser->arg[1][0] == '~')
		apath = ft_strjoin(ft_dic_get_value(all->env, "HOME")->value,
				 &parser->arg[1][1]);
	else
		apath = ft_strdup(parser->arg[1]);
	return (apath);
}

void	ft_cd(t_all *all, t_parser *parser)
{
	char	pwd[1024];
	char	*apath;

	apath = ft_get_apath(all, parser);
	if (apath == NULL)
		return ;
	if (chdir(apath) != 0)
	{
		ft_error("No such file or directory", apath);
		all->err = 1;
		return ;
	}
	getcwd(pwd, 1024);
	free(ft_dic_get_value(all->env, "OLDPWD")->value);
	ft_dic_get_value(all->env, "OLDPWD")->value
	= ft_dic_get_value(all->env, "PWD")->value;
	ft_dic_get_value(all->env, "PWD")->value = ft_strdup(pwd);
	all->err = 0;
	free(apath);
}
