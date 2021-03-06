/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:21:00 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 15:03:20 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_error(char *text, char *arg)
{
	ft_putstr_fd("AssZatshell", FD_ERR);
	ft_putstr_fd(": ", FD_ERR);
	ft_putstr_fd(text, FD_ERR);
	ft_putstr_fd(": ", FD_ERR);
	ft_putstr_fd(arg, FD_ERR);
	ft_putchar_fd('\n', FD_ERR);
	return (0);
}
