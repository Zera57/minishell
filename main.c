/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:59:49 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/12 15:16:21 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void ls(char **env)
{
	pid_t pid;
	char **test;
	test = malloc(8 * 3);
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
	// signal(SIGINT, );
	all.parser.arg = ft_split("zat=123", '|');

	// TESTING
	// // CD
	// ft_cd(&all, "~/Desktop");
	// char *temp = getwd(NULL);
	// printf("%s\n", temp);

	// // PWD
	// ft_pwd(&all);

	// EXPORT ADD
	ft_export_add(&all);
	
	// ENV
	ft_env(&all);
	// // UNSET
	// ft_unset(&all);
	// ft_env(&all);

	// // ECHO
	// ft_echo(&all);
	printf("\n\n");

	// EXPORT
	ft_export(&all);
	
	// // EXIT
	// ft_exit(&all);

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