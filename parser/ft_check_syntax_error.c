/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:32:39 by larlena           #+#    #+#             */
/*   Updated: 2021/05/23 15:31:07 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_check_syntax_error_shielding(const char *str, size_t	*i)
{
	if (str[*i] == '\\')
		(*i)++;
	if (!str[*i] || str[*i] == ' ')
		return (ft_return_error("syntax error", "shielding error"));
	(*i)++;
	return (0);
}

int	ft_check_syntax_error_double_quotes(const char *str, size_t	*i)
{
	while (str[++(*i)] && str[*i] != '\"')
	{
		if (str[*i] == '\\')
		{
			if (ft_check_syntax_error_shielding(str, i))
				return (1);
			else
				(*i)--;
		}
	}
	if (!str[*i])
		return (ft_return_error("syntax error", "double quotes error"));
	(*i)++;
	return (0);
}

int	ft_check_syntax_error_single_quotes(const char *str, size_t *i)
{
	while (str[++(*i)] && str[*i] != '\'')
		;
	if (!str[*i])
		return (ft_return_error("syntax error", "single quotes error"));
	(*i)++;
	return (0);
}

int	ft_check_syntax_error_special_symbol(const char *str)
{
	size_t	i;
	size_t	flag;

	i = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] == '|' || str[i] == ';')
		{
			if (flag)
				return (ft_return_error("syntax shell"
						, "special symbol error"));
			flag = i;
		}
		else if (str[i] != ' ')
			flag = 0;
		i++;
	}
	if (ft_isspecial_symbols(str[flag]) && str[flag] != ';')
		return (ft_return_error("syntax shell", "special symbol error"));
	return (0);
}

int	ft_check_syntax_error(const char *str)
{
	size_t	i;
	int		error;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			error = ft_check_syntax_error_double_quotes(str, &i);
		else if (str[i] == '\\')
			error = ft_check_syntax_error_shielding(str, &i);
		else if (str[i] == '\'')
			error = ft_check_syntax_error_single_quotes(str, &i);
		else
			i++;
		if (error)
			return (error);
	}
	if (ft_check_syntax_error_special_symbol(str))
		return (1);
	return (0);
}
