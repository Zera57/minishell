/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:25:33 by larlena           #+#    #+#             */
/*   Updated: 2021/05/19 10:25:51 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_add_slash(char **src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		ft_rewrite(&src[i], '/');
		i++;
	}
}

size_t	ft_arrlen(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_add_emty_line(char **src)
{
	char	**dst;
	size_t	arrsize;

	arrsize = ft_arrlen(src);
	dst = ft_rewrite_arr(src, arrsize);
	dst[arrsize] = ft_strdup("");
	return (dst);
}
