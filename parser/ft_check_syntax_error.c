/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:32:39 by larlena           #+#    #+#             */
/*   Updated: 2021/05/19 17:24:06 by larlena          ###   ########.fr       */
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

int	ft_check_syntax_error_special_symbol
		(const char *str, size_t *i, int *first_comand)
{
	size_t	j;

	if (str[*i] == '>' && str[*i + 1] == '>')
		*i += 1;
	j = *i + 1;
	ft_skip_space(str, (int *) &j);
	j++;
	if ((!str[j] || ft_isspecial_symbols(str[j])) && !(!str[j] && str[*i] == ';'))
		return (ft_return_error("syntax error", "special symbol error"));
	if (!*first_comand)
		return (ft_return_error("syntax error", "special symbol error"));
	(*i) = j;
	*first_comand += 0;
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

int	ft_check_syntax_error(const char *str)
{
	size_t	i;
	int		error;
	int		first_command;

	i = 0;
	first_command = 0;
	while (str[i])
	{
		if (str[i] == '"')
			error = ft_check_syntax_error_double_quotes(str, &i);
		else if (str[i] == '\\')
			error = ft_check_syntax_error_shielding(str, &i);
		else if (str[i] == '\'')
			error = ft_check_syntax_error_single_quotes(str, &i);
		else if (ft_isspecial_symbols(str[i]))
			error = ft_check_syntax_error_special_symbol(str, &i, &first_command);
		else
		{
			if (ft_isalnum(str[i]))
				first_command += 1;
			i++;
		}
		if (error)
			return (error);
	}
	return (0);
}



