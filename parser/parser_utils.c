/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:28:15 by larlena           #+#    #+#             */
/*   Updated: 2021/04/21 19:14:41 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clear_parser(t_list *parser)
{
	while (parser)
	{
		ft_free(((t_parser *)parser->content)->arg);
		free(parser->content);
		free(parser);
		parser = parser->next;
	}
}

void	ft_create_new_list_parser(t_list **parser)
{
	ft_lstadd_front(parser, ft_lstnew(malloc(sizeof(t_parser))));
	((t_parser *)(*parser)->content)->arg = ft_calloc(sizeof(char *), 2);
	((t_parser *)(*parser)->content)->arg[0] = ft_calloc(sizeof(char), 1);
}

void	ft_initialization_struct_parser(t_all *all, t_list **parser)
{
	all->ln = 0;
	ft_create_new_list_parser(parser);
	(*parser)->next = NULL;
}

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
