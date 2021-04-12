/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:01:53 by larlena           #+#    #+#             */
/*   Updated: 2021/04/12 20:06:03 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_dllist
{
	char				*str;
	struct s_dllist		*previous;
	struct s_dllist		*next;
}						t_dllist;

typedef struct s_dictionary
{
	char				*key;
	char				*value;
	struct s_dictionary	*next;
}						t_dictionary;

typedef struct s_parser
{
	char				**arg;
	int					i;
	int					fd_r;
	int					fd_w;
}						t_parser;

typedef struct s_all
{
	char				str[2056];
	char				buff[100];
	int					i;
	char				**envc;
	char				*flags;
	t_dictionary		*env;
	t_dllist			*history;
	t_parser			*parser;
}						t_all;

#endif