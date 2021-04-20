/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:44:47 by larlena           #+#    #+#             */
/*   Updated: 2021/04/20 18:25:13 by larlena          ###   ########.fr       */
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
			ft_redirects(all, ((t_parser *)(*parser)->content));
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

// void	sozdanie_env(char **peremennaia)
// {
// 	peremennaia[0] = ft_strdup("TMPDIR=/var/folders/zz/zyxvpxvq6csfxvn_n003vhh000yw40/T/");
// 	peremennaia[1] = ft_strdup("SHELL=/bin/zsh");
// 	peremennaia[2] = ft_strdup("HOME=/Users/larlena");
// 	peremennaia[3] = ft_strdup("SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.Gaxnf5gjKh/Listeners");
// 	peremennaia[4] = ft_strdup("Apple_PubSub_Socket_Render=/private/tmp/com.apple.launchd.DJ5Icd6009/Render");
// 	peremennaia[5] = ft_strdup("LOGNAME=larlena");
// 	peremennaia[6] = ft_strdup("PATH=/Users/larlena/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki");
// 	peremennaia[7] = ft_strdup("XPC_SERVICE_NAME=0");
// 	peremennaia[8] = ft_strdup("COMMAND_MODE=unix2003");
// 	peremennaia[9] = ft_strdup("USER=larlena");
// 	peremennaia[10] = ft_strdup("SECURITYSESSIONID=186a7");
// 	peremennaia[11] = ft_strdup("XPC_FLAGS=0x0");
// 	peremennaia[12] = ft_strdup("__CF_USER_TEXT_ENCODING=0xF7080:0x0:0x0");
// 	peremennaia[13] = ft_strdup("ORIGINAL_XDG_CURRENT_DESKTOP=undefined");
// 	peremennaia[14] = ft_strdup("TERM_PROGRAM=vscode");
// 	peremennaia[15] = ft_strdup("TERM_PROGRAM_VERSION=1.55.2");
// 	peremennaia[16] = ft_strdup("LANG=en_US.UTF-8");
// 	peremennaia[17] = ft_strdup("COLORTERM=truecolor");
// 	peremennaia[18] = ft_strdup("VSCODE_GIT_IPC_HANDLE=/var/folders/zz/zyxvpxvq6csfxvn_n003vhh000yw40/T/vscode-git-0db997ab38.sock");
// 	peremennaia[19] = ft_strdup("GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh");
// 	peremennaia[20] = ft_strdup("VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Renderer).app/Contents/MacOS/Code Helper (Renderer)");
// 	peremennaia[21] = ft_strdup("VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js");
// 	peremennaia[22] = ft_strdup("PWD=/Users/larlena/Documents/my_git/minishell");
// 	peremennaia[23] = ft_strdup("TERM=xterm-256color");
// 	peremennaia[24] = ft_strdup("SHLVL=1");
// 	peremennaia[25] = ft_strdup("OLDPWD=/Users/larlena/Documents/my_git/minishell");
// 	peremennaia[26] = ft_strdup("ZSH=/Users/larlena/.oh-my-zsh");
// 	peremennaia[27] = ft_strdup("PAGER=less");
// 	peremennaia[28] = ft_strdup("LESS=-R");
// 	peremennaia[29] = ft_strdup("LSCOLORS=Gxfxcxdxbxegedabagacad");
// 	peremennaia[30] = ft_strdup("HOMEBREW_CACHE=/tmp/larlena/Homebrew/Caches");
// 	peremennaia[31] = ft_strdup("HOMEBREW_TEMP=/tmp/larlena/Homebrew/Temp");
// 	peremennaia[32] = ft_strdup("_=/usr/bin/env");
// }

// int main(int argc, char **argv, char **env)
// {
// 	int		j;
//     t_all all;
// 	all.env = NULL;
// 	all.envc = NULL;
// 	char **peremennaia;

// 	peremennaia = calloc(sizeof(char *), 50);
// 	sozdanie_env(peremennaia);
// 	ft_set_env(&all, peremennaia);
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
