/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:01:53 by larlena           #+#    #+#             */
/*   Updated: 2021/05/17 14:06:46 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../Libft/libft.h"

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
	int					pipefd[2];
	int					redfd[2];
}						t_parser;

typedef struct s_all
{
	char				str[2056];
	char				buff[100];
	int					i;
	int					j;
	int					ln;
	char				**envc;
	char				*flags;
	t_dictionary		*env;
	t_dllist			*history;
	t_list				*parser;
	int					syntax_error;
	int					err;
}						t_all;

#endif