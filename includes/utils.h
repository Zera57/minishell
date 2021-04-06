/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:13:58 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/06 18:13:01 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAP_H
# define TERMCAP_H

# include "minishell.h"

typedef struct s_dllist
{
	char			*str;
	struct s_dllist	*previous;
	struct s_dllist	*next;
}				t_dllist;

typedef struct s_dictionary
{
	char				*key;
	char				*value;
	struct s_dictionary	*next;
}				t_dictionary;

t_dllist		*ft_dllstnew(char *str);
void			ft_dllstadd_front(t_dllist *lst, char *str);
void			ft_dllstadd_back(t_dllist *lst, char *str);
t_dllist		*ft_dllstbegining(t_dllist *lst);

t_dictionary	*ft_dicnew(char *key, char *value);
void			ft_dicadd_front(t_dictionary **lst, t_dictionary *new);
void			ft_dicadd_back(t_dictionary *lst, t_dictionary *new);
t_dictionary	*ft_dic_get_value(t_dictionary *lst, char *key);

#endif