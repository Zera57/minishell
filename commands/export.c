/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:42:09 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 16:10:50 by hapryl           ###   ########.fr       */
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

static char	**ft_get_export(char *str)
{
	char	**result;
	char	*temp;

	temp = ft_strchr(str, '=');
	if (temp == NULL)
	{
		result = (char **)ft_malloc(2 * sizeof(char *));
		result[0] = ft_strdup(str);
		result[1] = NULL;
		return (result);
	}
	result = (char **)ft_malloc(3 * sizeof(char *));
	*temp = 0;
	temp++;
	result[0] = ft_strdup(str);
	result[1] = ft_strdup(temp);
	result[2] = NULL;
	return (result);
}

void	ft_export_set(t_all *all, char **str)
{
	t_dictionary	*dic;

	dic = ft_dic_get_value(all->env, str[0]);
	if (dic == NULL)
		ft_dicadd_back(all->env, ft_dicnew(str[0], str[1]));
	else
	{
		free(str[0]);
		if (str[1] != NULL)
		{
			if (dic->value != NULL)
				free(dic->value);
			dic->value = str[1];
		}
	}
}

void	ft_export_add(t_all *all, t_parser *parser)
{
	int				i;
	char			**str;

	i = 0;
	while (parser->arg[++i])
	{
		str = ft_get_export(parser->arg[i]);
		if (validate_name(str[0]))
		{
			ft_export_set(all, str);
			free(str);
		}
		else
			ft_free(str);
	}
}

void	ft_export(t_all *all)
{
	int		i;

	i = 0;
	all->err = 0;
	ft_get_env2(all);
	sort_by_name(all, ft_dic_lenght(all->env));
	while (all->envc[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(all->envc[i++], 1);
	}
}
