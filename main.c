/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:59:49 by hapryl            #+#    #+#             */
/*   Updated: 2021/04/06 15:41:45 by hapryl           ###   ########.fr       */
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
		waitpid(pid, 0, 0);
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
	ft_set_env(&all, env);
	
	// testing env and dictionaries
	t_dictionary *temp = ft_dic_get_value(all.env, "PWD");
	printf("%s\n", temp->value);

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, term_name);

	while (strcmp(all.buff, "\4"))
	{
		ft_analize_string(&all);
	}
	return (0);
}