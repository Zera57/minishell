/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:48:36 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 11:03:46 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_type(t_all *all)
{
	all->str[all->i] = all->buff[0];
	all->i++;
	all->str[all->i] = '\0';
	if (all->history->next == NULL)
	{
		free(all->history->str);
		all->history->str = ft_strdup(all->str);
	}
	write(1, all->buff, 1);
	return (0);
}

void	termcap_on(void)
{
	struct termios	term;
	char			*term_name = "xterm-256color";

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, term_name);
}

void	termcap_off(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag ^= (ECHO);
	term.c_lflag ^= (ICANON);
	tcsetattr(0, TCSANOW, &term);
}
