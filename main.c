/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:59:49 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/23 12:16:44 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void ls(char **env)
{
	pid_t pid;
	char **test;
	test = ft_malloc(8 * 3);
	test[0] = ft_strdup("ls");
	test[1] = ft_strdup("-la");
	test[2] = NULL;
	if ((pid = fork()) == -1)
		exit(1);
	if (pid == 0) {	
		if (execve("/bin/ls", test, env) == -1)
			printf("error\n");
	}
	else {
		// waitpid(pid, 0, 0);
		printf("end");
	}
}

int main(int argc, char **argv, char **env)
{
	t_all			all;
	struct termios	term;
	char			*term_name = "xterm-256color";
	
	all.history = ft_dllstnew(ft_strdup(""));
	all.i = 0;
	all.env = NULL;
	all.envc = NULL;
	ft_set_env(&all, env);
	// // signal(SIGINT, );

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, term_name);

	write(1, "(っ＾▿＾)۶🍸🌟🍺٩(˘◡˘ ): ", ft_strlen("(っ＾▿＾)۶🍸🌟🍺٩(˘◡˘ ): "));
	while (strcmp(all.buff, "\4"))
	{
		ft_analize_string(&all);
	}
	return (0);
}