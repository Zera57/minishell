/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:55:52 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 19:43:37 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_arrow_up(t_all *all)
{
	if (all->history != NULL && all->history->previous != NULL)
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		all->history = all->history->previous;
		all->i = ft_strlen(all->history->str);
		ft_memcpy(all->str, all->history->str, all->i);
		all->str[all->i] = 0;
		write(1, all->str, all->i);
	}
	return (0);
}

int		ft_arrow_down(t_all *all)
{
	if (all->history != NULL && all->history->next != NULL)
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		all->history = all->history->next;
		all->i = ft_strlen(all->history->str);
		ft_memcpy(all->str, all->history->str, all->i);
		all->str[all->i] = 0;
		write(1, all->str, all->i);
	}
	return (0);
}

int		ft_backspace(t_all *all)
{
	if (all->i > 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		all->str[--all->i] = 0;
	}
	return (0);
}

int		ft_enter(t_all *all)
{
	all->history = ft_dllstbegining(all->history);
	free(all->history->str);
	all->history->str = ft_strdup(all->str);
	ft_dllstadd_front(all->history, ft_strdup(""));
	all->history = ft_dllstbegining(all->history);
	all->str[all->i] = 0;
	write(1, "\n", 1);
	termcap_off();
	ft_parser(all, &all->parser, all->str);
	termcap_on();
	all->i = 0;
	return (0);
}

int		ft_analize_buf(t_all *all)
{
	int l;

	l = read(0, all->buff, 10);
	all->buff[l] = 0;
	if (!ft_strcmp(all->buff, "\e[A"))
		ft_arrow_up(all);
	else if (!ft_strcmp(all->buff, "\e[B"))
		ft_arrow_down(all);
	else if (!ft_strcmp(all->buff, key_backspace) || !ft_strcmp(all->buff, "\177"))
		ft_backspace(all);
	else if (!ft_strcmp(all->buff, key_enter) || !ft_strcmp(all->buff, "\n"))
		ft_enter(all);
	else if (all->buff[0] == '\e' || all->buff[0] == '\t')
		;
	else if (ft_isascii(all->buff[0]))
		ft_type(all);
	return (l);
}
