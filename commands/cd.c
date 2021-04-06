/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:50:23 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/06 19:57:53 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commands.h"

void	ft_cd(t_all *all, char *path)
{
	char	*apath;
	if (path[0] == '~')
		apath = ft_strjoin(ft_dic_get_value(all->env, "HOME")->value, &path[1]);
	else
		apath = path;
	free(ft_dic_get_value(all->env, "OLDPWD")->value);
	ft_dic_get_value(all->env, "OLDPWD")->value = ft_dic_get_value(all->env, "PWD")->value;
	ft_dic_get_value(all->env, "PWD")->value = apath;
	chdir(apath);
	printf("Changed directory %s\n", apath);
	return ;
}
