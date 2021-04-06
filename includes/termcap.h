/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:13:58 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/06 11:34:40 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAP_H
# define TERMCAP_H

#include "minishell.h"

typedef struct s_dllist
{
	char			*str;
	struct s_dllist	*previous;
	struct s_dllist	*next;
}				t_dllist;




t_dllist	*ft_dllstnew(char *str);
void		ft_dllstadd_front(t_dllist *lst, char *str);
void		ft_dllstadd_back(t_dllist *lst, char *str);
t_dllist	*ft_dllstbegining(t_dllist *lst);


#endif