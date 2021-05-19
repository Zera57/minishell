/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:59:49 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 19:47:28 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	f(int a)
{
	a++;
	write(1, "\n", 1);
	if (all.parser == NULL)
		write(1, "(っ＾▿＾)۶🍸🌟🍺٩(˘◡˘ ): ", ft_strlen("(っ＾▿＾)۶🍸🌟🍺٩(˘◡˘ ): "));
	ft_bzero(all.str, 2056);
	all.err = 130;
}

void	f2(int a)
{
	a++;
	if (all.parser != NULL)
		write(1, "Quit: 3\n", ft_strlen("Quit: 3\n"));
	all.err = 131;
}

int	main(int argc, char **argv, char **env)
{
	t_dictionary	*dic;
	char			*temp;

	if (argc != 1)
	{
		ft_error(argv[1], "No such file or directory");
		exit(127);
	}
	signal(SIGINT, &f);
	signal(SIGQUIT, &f2);
	argc = (int)argv[1][1];
	all.history = ft_dllstnew(ft_strdup(""));
	all.i = 0;
	all.env = NULL;
	all.envc = NULL;
	ft_set_env(&all, env);
	dic = ft_dic_get_value(all.env, "SHLVL");
	temp = ft_itoa(ft_atoi(dic->value) + 1);
	free(dic->value);
	dic->value = temp;
	termcap_on();
	while (1)
	{
		ft_analize_string(&all);
		if (!ft_strcmp(all.buff, "\4") && (all.str[0] == 4 || all.str[0] == 0))
			break;
		ft_bzero(all.str, 2056);
	}
	ft_putendl_fd("exit", 1);
	return (all.err);
}
