/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:13:58 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 13:41:05 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

t_dllist		*ft_dllstnew(char *str);
void			ft_dllstadd_front(t_dllist *lst, char *str);
void			ft_dllstadd_back(t_dllist *lst, char *str);
t_dllist		*ft_dllstbegining(t_dllist *lst);

t_dictionary	*ft_dicnew(char *key, char *value);
int				ft_dic_lenght(t_dictionary *lst);
void			ft_dicadd_back(t_dictionary *lst, t_dictionary *new);
t_dictionary	*ft_dic_get_value(t_dictionary *lst, char *key);
t_dictionary	*ft_dic_delete(t_dictionary *start, char *key);

// PARSER UTILS

pid_t			protected_fork(void);
size_t			ft_arrlen(char **str);
void			ft_rewrite(char **src, char c);
void			ft_add_slash(char **src);
void			ft_skip_space(const char *str, int *i);
void			ft_clear_parser(t_list *parser);
char			**ft_rewrite_arr(char **arg, size_t size);
char			**ft_add_emty_line(char **src);
t_list			*ft_search_previous(t_list *begin, t_list *present);
int				ft_isspecial_symbols(char c);
void			ft_create_new_list_parser(t_list **parser);
void			ft_initialization_struct_parser(t_all *all, t_list **parser);

#endif