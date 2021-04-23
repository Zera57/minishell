/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:50:23 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/23 21:12:50 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.h"

void	ft_cd(t_all *all, t_parser *parser)
{
	char	*apath;

	if (parser->arg[1][0] == '~')
		apath = ft_strjoin(ft_dic_get_value(all->env, "HOME")->value, &parser->arg[1][1]);
	else
		apath = parser->arg[1];
	free(ft_dic_get_value(all->env, "OLDPWD")->value);
	ft_dic_get_value(all->env, "OLDPWD")->value
	= ft_dic_get_value(all->env, "PWD")->value;
	ft_dic_get_value(all->env, "PWD")->value = apath;
	if (chdir(apath) != 0)
		ft_error("minishell: cd:", "No such file or directory", parser->arg[1]);
	else
		printf("Changed directory %s\n", apath);
}
