/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:44:47 by larlena           #+#    #+#             */
/*   Updated: 2021/04/20 15:53:52 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_parser(t_all *all, t_list **parser, const char *str)
{
	all->j = -1;
	ft_initialization_struct_parser(all, parser);
	while (str[++all->j])
	{
		if (str[all->j] == ';')
			ft_semicolon(all, parser, str);
		else if (str[all->j] == '|')
			ft_pipe(all, parser);
		else if (str[all->j] == '>' || str[all->j] == '<')
			;
		else if (str[all->j] == '"')
			ft_parsing_double_quotes(all, *parser, str);
		else if (str[all->j] == '\'')
			ft_parsing_single_quotes(all, *parser, str);
		else if (str[all->j] == ' ')
			ft_parsing_space(all, *parser, str);
		else
			((t_parser *)(*parser)->content)->arg[all->ln] =
			ft_rewrite(((t_parser *)(*parser)->content)->arg[all->ln], str[all->j]);
	}
	ft_command_execution(all);
	return (0);
}

// void	sozdanie_env(char **hueta)
// {
// 	hueta[0] = ft_strdup("TMPDIR=/var/folders/zz/zyxvpxvq6csfxvn_n003vhh000yw40/T/");
// 	hueta[1] = ft_strdup("SHELL=/bin/zsh");
// 	hueta[2] = ft_strdup("HOME=/Users/larlena");
// 	hueta[3] = ft_strdup("SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.Gaxnf5gjKh/Listeners");
// 	hueta[4] = ft_strdup("Apple_PubSub_Socket_Render=/private/tmp/com.apple.launchd.DJ5Icd6009/Render");
// 	hueta[5] = ft_strdup("LOGNAME=larlena");
// 	hueta[6] = ft_strdup("PATH=/Users/larlena/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki");
// 	hueta[7] = ft_strdup("XPC_SERVICE_NAME=0");
// 	hueta[8] = ft_strdup("COMMAND_MODE=unix2003");
// 	hueta[9] = ft_strdup("USER=larlena");
// 	hueta[10] = ft_strdup("SECURITYSESSIONID=186a7");
// 	hueta[11] = ft_strdup("XPC_FLAGS=0x0");
// 	hueta[12] = ft_strdup("__CF_USER_TEXT_ENCODING=0xF7080:0x0:0x0");
// 	hueta[13] = ft_strdup("ORIGINAL_XDG_CURRENT_DESKTOP=undefined");
// 	hueta[14] = ft_strdup("TERM_PROGRAM=vscode");
// 	hueta[15] = ft_strdup("TERM_PROGRAM_VERSION=1.55.2");
// 	hueta[16] = ft_strdup("LANG=en_US.UTF-8");
// 	hueta[17] = ft_strdup("COLORTERM=truecolor");
// 	hueta[18] = ft_strdup("VSCODE_GIT_IPC_HANDLE=/var/folders/zz/zyxvpxvq6csfxvn_n003vhh000yw40/T/vscode-git-0db997ab38.sock");
// 	hueta[19] = ft_strdup("GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh");
// 	hueta[20] = ft_strdup("VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Renderer).app/Contents/MacOS/Code Helper (Renderer)");
// 	hueta[21] = ft_strdup("VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js");
// 	hueta[22] = ft_strdup("PWD=/Users/larlena/Documents/my_git/minishell");
// 	hueta[23] = ft_strdup("TERM=xterm-256color");
// 	hueta[24] = ft_strdup("SHLVL=1");
// 	hueta[25] = ft_strdup("OLDPWD=/Users/larlena/Documents/my_git/minishell");
// 	hueta[26] = ft_strdup("ZSH=/Users/larlena/.oh-my-zsh");
// 	hueta[27] = ft_strdup("PAGER=less");
// 	hueta[28] = ft_strdup("LESS=-R");
// 	hueta[29] = ft_strdup("LSCOLORS=Gxfxcxdxbxegedabagacad");
// 	hueta[30] = ft_strdup("HOMEBREW_CACHE=/tmp/larlena/Homebrew/Caches");
// 	hueta[31] = ft_strdup("HOMEBREW_TEMP=/tmp/larlena/Homebrew/Temp");
// 	hueta[32] = ft_strdup("_=/usr/bin/env");
// }

// int main(int argc, char **argv, char **env)
// {
// 	int		j;
//     t_all all;
// 	all.env = NULL;
// 	all.envc = NULL;
// 	char **hueta;

// 	hueta = calloc(sizeof(char *), 50);
// 	sozdanie_env(hueta);
// 	ft_set_env(&all, hueta);
//     ft_strlcpy(all.str, "ls ", 122);
// 	ft_parser(&all, &all.parser, all.str);
// 	// while(1);
// 	// while (all.parser != NULL)
// 	// {
// 	// 	j = 0;
// 	// 	while (((t_parser *)all.parser->content)->arg[j])
// 	// 	{
// 	// 		printf("\"%s\"\t", ((t_parser *)all.parser->content)->arg[j]);
// 	// 		j++;
// 	// 	}
// 	// 	printf("\n");
// 	// 	all.parser = all.parser->next;
// 	// }
// 	return (0);
// }
