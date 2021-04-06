/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:25:00 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/06 11:33:49 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_dllist	*ft_dllstnew(char *str)
{
	t_dllist	*lst;
	lst = malloc(sizeof(t_dllist));
	lst->str = ft_strdup(str);
	lst->previous = NULL;
	lst->next = NULL;
	return (lst);
}

void		ft_dllstadd_back(t_dllist *lst, char *str)
{
	if (!lst)
		return ;
	while (lst->previous != NULL)
		lst = lst->previous;
	lst->previous = ft_dllstnew(str);
	lst->previous->next = lst;
}

void		ft_dllstadd_front(t_dllist *lst, char *str)
{
	if (!lst)
		return ;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = ft_dllstnew(str);
	lst->next->previous = lst;
}

t_dllist	*ft_dllstbegining(t_dllist *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}