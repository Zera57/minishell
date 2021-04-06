/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:55:52 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/06 15:28:59 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_analize_string(t_all *all)
{
	int	l;

	tputs(save_cursor, 1, ft_putchar);
	do
	{
		l = read(0, all->buff, 10);
		all->buff[l] = 0;
		if (!ft_strcmp(all->buff, "\e[A"))
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
		}
		else if (!ft_strcmp(all->buff, "\e[B"))
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
		}
		else if (!ft_strcmp(all->buff, key_backspace) || !ft_strcmp(all->buff, "\177"))
		{
			tputs(cursor_left, 1, ft_putchar);
			tputs(tgetstr("dc", 0), 1, ft_putchar);
			all->str[--all->i] = 0;
		}
		else if (!ft_strcmp(all->buff, key_enter) || !ft_strcmp(all->buff, "\n"))
		{
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tigetstr("ed"), 1, ft_putchar);
			write(1, all->str, all->i);
			write(1, all->buff, l);
			all->history = ft_dllstbegining(all->history);
			free(all->history->str);
			all->history->str = ft_strdup(all->str);
			ft_dllstadd_front(all->history, ft_strdup(""));
			all->history = ft_dllstbegining(all->history);
			all->i = 0;
		}
		else if (ft_isalnum(all->buff[0]))
		{
			all->str[all->i] = all->buff[0];
			all->i++;
			all->str[all->i] = '\0';
			if (all->history->next == NULL)
			{
				free(all->history->str);
				all->history->str = ft_strdup(all->str);
			}
			write(1, all->buff, l);
		}
	} while (ft_strcmp(all->buff, "\n") && ft_strcmp(all->buff, "\4"));
	return (0);
}