/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:28:15 by larlena           #+#    #+#             */
/*   Updated: 2021/04/12 20:08:42 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_parsing_double_quotes(t_all *all, char *arg, const char *str, size_t i)
{
	while (str[++i] && str[i] != '"')
	{
		if (str[i] == '\\')
		{
			i++;
			if ()
		}
	}
	return (i);
}

char	**ft_rewrite_arr(char **arg, size_t size)
{
	char	**dst;
	size_t	i;

	i = -1;
	dst = calloc(sizeof(char *), size + 1);
	if (!dst)
		return (NULL);
	while (++i < size)
		dst[i] = arg[i];
	return (dst);
}

char	*ft_rewrite(char *src, char c)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(src);
	dst = ft_calloc(sizeof(char), size + 2);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, size);
	dst[size] = c;
	free(src);
	return (dst);
}
