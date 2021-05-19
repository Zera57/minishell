/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:42:09 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 15:06:21 by larlena          ###   ########.fr       */
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

int	validate_name(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		all.err = 1;
		return (ft_error("not an identifier", str));
	}
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			all.err = 1;
			return (ft_error("not an identifier", str));
		}
		i++;
	}
	return (1);
}

static char	**ft_get_export(char *str)
{
	char	**result;
	char	*temp;

	temp = ft_strchr(str, '=');
	if (temp == NULL)
	{
		result = (char**)ft_malloc(2 * sizeof(char*));
		result[0] = ft_strdup(str);
		result[1] = NULL;
		return (result);
	}
	result = (char**)ft_malloc(3 * sizeof(char*));
	*temp = 0;
	temp++;
	result[0] = ft_strdup(str);
	result[1] = ft_strdup(temp);
	result[2] = NULL;
	return (result);
}

void	ft_export_add(t_all *all, t_parser *parser)
{
	int				i;
	char			**str;
	t_dictionary	*dic;

	i = 0;
	while (parser->arg[++i])
	{
		str = ft_get_export(parser->arg[i]);
		if (str[1] == NULL && ft_strchr(parser->arg[i], '='))
			str[1] = ft_strdup("");
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
	}
}

void	ft_export(t_all *all)
{
	int		i;

	i = 0;
	all->err = 0;
	ft_get_env(all);
	sort_by_name(all, ft_dic_lenght(all->env));
	while (all->envc[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(all->envc[i++], 1);
	}
}
