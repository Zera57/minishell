/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:28:15 by larlena           #+#    #+#             */
/*   Updated: 2021/04/13 15:14:15 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_rewrite_arr(char **arg, size_t size)
{
	char	**dst;
	size_t	i;

	i = -1;
	dst = (char **)calloc(sizeof(char *), size + 2);
	if (!dst)
		return (NULL);
	while (++i < size)
		dst[i] = arg[i];
	free(arg);
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
