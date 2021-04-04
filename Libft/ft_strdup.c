/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:43:09 by larlena           #+#    #+#             */
/*   Updated: 2021/04/04 17:52:26 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	end;
	size_t	i;

	i = 0;
	end = ft_strlen(s1) + 1;
	dst = ft_calloc(sizeof(char), end);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, end + 1);
	return (dst);
}
