/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:33:09 by larlena           #+#    #+#             */
/*   Updated: 2021/04/04 17:54:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	max;
	char	*dst;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	max = ft_strlen(s);
	dst = ft_calloc(sizeof(char), max + 1);
	if (dst == NULL)
		return (NULL);
	while (i < max)
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	return (dst);
}
