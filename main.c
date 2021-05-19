/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:59:49 by hapryl            #+#    #+#             */
/*   Updated: 2021/05/19 16:44:43 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	f(int a)
{
	a++;
	write(1, "\n(っ＾▿＾)۶🍸🌟🍺٩(˘◡˘ ): ", ft_strlen("\n(っ＾▿＾)۶🍸🌟🍺٩(˘◡˘ ): "));
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
		ft_error("minishell", argv[1], "No such file or directory");
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
	while (ft_strcmp(all.buff, "\4"))
		ft_analize_string(&all);
	ft_putendl_fd("exit", 1);
	return (0);
}
