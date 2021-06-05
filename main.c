/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zera <zera@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:59:49 by hapryl            #+#    #+#             */
/*   Updated: 2021/06/05 11:53:16 by zera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	f(int a)
{
	a++;
}

void	f1(int a)
{
	a++;
	write(1, "\n", 1);
	if (g_all.parser == NULL)
		write(1, "(っ＾▿＾)۶🍸🌟🍺٩(˘◡˘ ): ", ft_strlen("(っ＾▿＾)۶🍸🌟🍺٩(˘◡˘ ): "));
	ft_bzero(g_all.str, 2056);
	g_all.err = 130;
}

void	f2(int a)
{
	a++;
	if (g_all.parser != NULL)
		write(1, "Quit: 3\n", ft_strlen("Quit: 3\n"));
	g_all.err = 131;
}

void	all_init(char **env)
{
	char			*temp;
	t_dictionary	*dic;

	g_all.history = ft_dllstnew(ft_strdup(""));
	g_all.i = 0;
	g_all.env = NULL;
	g_all.envc = NULL;
	ft_set_env(&g_all, env);
	dic = ft_dic_get_value(g_all.env, "SHLVL");
	if (dic)
	{
		temp = ft_itoa(ft_atoi(dic->value) + 1);
		free(dic->value);
		dic->value = temp;
	}
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 1)
	{
		ft_error(argv[1], "No such file or directory");
		exit(127);
	}
	signal(SIGINT, &f1);
	signal(SIGQUIT, &f2);
	all_init(env);
	termcap_on();
	while (1)
	{
		ft_analize_string(&g_all);
		ft_bzero(g_all.str, 2056);
	}
	ft_putendl_fd("exit", 1);
	termcap_off();
	return (g_all.err);
}
