/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:59:49 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 20:50:26 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	f(int a)
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

void	all_init(void)
{
	char			*temp;
	t_dictionary	*dic;

	g_all.history = ft_dllstnew(ft_strdup(""));
	g_all.i = 0;
	g_all.env = NULL;
	g_all.envc = NULL;
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
	signal(SIGINT, &f);
	signal(SIGQUIT, &f2);
	argc = (int)argv[1][1];
	all_init();
	ft_set_env(&g_all, env);
	termcap_on();
	while (1)
	{
		ft_analize_string(&g_all);
		if (!ft_strcmp(g_all.buff, "\4") && (g_all.str[0] == 4 || g_all.str[0] == 0))
			break ;
		ft_bzero(g_all.str, 2056);
	}
	ft_putendl_fd("exit", 1);
	return (g_all.err);
}
