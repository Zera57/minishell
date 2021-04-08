/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:42:09 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/08 17:45:50 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**sort_by_name(t_all *all, int numitems)
{
	int		i;
	int		didSwap;
	int		limit;
	char	*temp;

	didSwap = 1;
	limit = numitems - 1;
	while (didSwap)
	{
		didSwap = 0;
		i = 0;
		while (i < limit)
		{
			if (ft_strcmp(all->envc[i], all->envc[i + 1]) > 0)
			{
				temp = all->envc[i];
				all->envc[i] = all->envc[i + 1];
				all->envc[i + 1] = temp;
				didSwap = 1;
			}
			i++;
		}
		limit--;
	}
	return (all->envc);
}

int		validate_name(char *str)
{
	int i;

	i = 0;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	ft_export_add(t_all *all)
{
	int				i;
	char			**str;
	t_dictionary	*dic;

	i = 0;
	while (all->arg[i])
	{
		str = ft_split(all->arg[i], '=');
		if (validate_name(str[0]))
		{
			dic = ft_dic_get_value(all->env, str[0]);
			if (dic == NULL)
				ft_dicadd_back(all->env, ft_dicnew(str[0], str[1]));
			else
			{
				free(str[0]);
				if (dic->value != NULL)
					free(dic->value);
				dic->value = str[1];
			}
			free(str);
		}
		else
			ft_free(str);
		i++;
	}
	// ft_array_free(all->arg, i);
}

void	ft_export(t_all *all)
{
	int		i;

	ft_get_env(all);
	sort_by_name(all, ft_dic_lenght(all->env));

	i = 0;
	while (all->envc[i])
		ft_putendl_fd(all->envc[i++], 1);
}