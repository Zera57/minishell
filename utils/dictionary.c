/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:51:02 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/08 13:41:40 by hapryl           ###   ########.fr       */
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

int				ft_dic_lenght(t_dictionary *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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
	while (lst)
	{
		if (!ft_strcmp(lst->key, key))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_dictionary	*ft_dic_delete(t_dictionary *start, char *key)
{
	t_dictionary	*lst;
	t_dictionary	*old;

	old = NULL;
	lst = start;
	while (lst)
	{
		if (!ft_strcmp(lst->key, key))
		{
			free(lst->key);
			if (lst->value)
				free(lst->value);
			if (lst == start)
				start = lst->next;
			else
				old->next = lst->next;
			free(lst);
			return (start);
		}
		old = lst;
		lst = lst->next;
	}
	return (start);
}
