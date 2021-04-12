/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:41:33 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/12 19:33:24 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_next_word(t_all *all)
{
	int		i;
	int		j;
	char	*str;

	i = all->parser.i;
	while (all->str[i] == ' ')
		i++;
	j = i;
	while (all->str[j] != ';' && all->str[j] != '|'
		&& all->str[j] != '>' && all->str[j] != '<' && all->str[j] != ' ')
		j++;
	str = malloc(j - i + 1);
	ft_strlcpy(str, &all->str[i], j - i + 1);
	return (str);
}

int		ft_redirect(t_all *all)
{
	char	*path;

	path = get_next_word(all);
	all->parser.fd_w = open(path, O_RDWR | O_CREAT | O_TRUNC);
	if (all->parser.fd_w < 0)
	{
		printf("Error");
		return (1);
	}
	return (0);
}
