/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zera <zera@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:02:48 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/08 18:53:09 by zera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_set_env(t_all *all, char **env)
{
	char	**temp;
	int		i;

	i = 0;
	while(env[i])
	{
		temp = ft_split(env[i], '=');
		if (all->env == NULL)
			all->env = ft_dicnew(temp[0], temp[1]);
		else
		{
			if (temp[1])
				ft_dicadd_back(all->env, ft_dicnew(temp[0], temp[1]));
			else
				ft_dicadd_back(all->env, ft_dicnew(temp[0], NULL));
		}
		free(temp);
		i++;
	}
}

char	*get_envline(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		j;
	int		lenght;

	i = 0;
	lenght = ft_strlen(str1) + ft_strlen(str2) + 2;
	str = malloc(lenght);
	while (i < lenght && i < ft_strlen(str1))
	{
		str[i] = str1[i];
		i++;
	}
	str[i++] = '=';
	j = 0;
	while (i < lenght && j < ft_strlen(str2))
	{
		str[i++] = str2[j++];
	}
	str[i] = 0;
	return (str);
}

char	**ft_get_env(t_all *all)
{
	t_dictionary	*dic;
	char			*temp;
	int				i;

	dic = all->env;
	if (all->envc != NULL)
		ft_array_free(all->envc, ft_dic_lenght(all->env));
	all->envc = malloc(sizeof(char *) * (ft_dic_lenght(all->env) + 1));
	i = 0;
	while (dic)
	{
		all->envc[i] = get_envline(dic->key, dic->value);
		dic = dic->next;
		i++;
	}
	all->envc[i] = NULL;
	return (all->envc);
}