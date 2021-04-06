/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:51:02 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/06 15:33:20 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_dictionary	*ft_dicnew(char *key, char *value)
{
	t_dictionary	*lst;
	lst = malloc(sizeof(t_dictionary));
	lst->key = key;
	lst->value = value;
	lst->next = NULL;
	return (lst);
}

void			ft_dicadd_front(t_dictionary **lst, t_dictionary *new)
{
	new->next = *lst;
	*lst = new;
}

void			ft_dicadd_back(t_dictionary *lst, t_dictionary *new)
{
	if (!lst)
		return ;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
}

t_dictionary	*ft_dic_get_value(t_dictionary *lst, char *key)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		if (!ft_strcmp(lst->key, key))
			return (lst);
		lst = lst->next;
	}
	if (!ft_strcmp(lst->key, key))
		return (lst);
	return (NULL);
}
