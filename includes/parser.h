/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:01:48 by larlena           #+#    #+#             */
/*   Updated: 2021/05/23 17:53:39 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

# define FD_W 1
# define FD_R 0
# define FD_ERR 2

int		ft_check_syntax_error(const char *str);

int		ft_redirects(t_all *all, t_parser *parser);
int		ft_semicolon(t_all *all, t_list **parser, const char *str);

void	ft_parsing_double_quotes(t_all *all, t_list *parser, const char *str);
void	ft_parsing_single_quotes(t_all *all, t_list *parser, const char *str);
int		ft_parsing_shielding(t_all *all, t_list *parser, const char *str);
void	ft_parsing_dollar(t_all *all, t_list *parser, const char *str);
void	ft_parsing_space(t_all *all, t_list *parser, const char *str);
int		ft_parsing_pipe(t_all *all, t_list **parser, const char *str);
void	ft_command_execution(t_all *all);

int		ft_search_commands(t_all *all, t_list *parser);
void	ft_search_fork_commands(t_all *all, t_list *parser, char *command);
int		ft_search_builtin_commands(t_all *all, t_list *parser, char *command);

int		ft_struct_pipe(t_list *parser);
void	ft_fd_replacement_last_elem(t_list *previous, t_list *present);
void	ft_fd_replacement_first_elem(t_list *present);
void	ft_fd_replacement_middle_elem(t_list *previous, t_list *present);
void	ft_fd_red_replacement_back(t_parser *parser);
void	ft_fd_red_replacement(t_parser *parser);
t_list	*ft_search_previous(t_list *begin, t_list *present);

int		ft_return_error(char *text, char *arg);
int		ft_executin_command(t_all *all, t_list *parser,
			char *path, char *command);
char	**ft_add_present_dir(void);

void	ft_create_pid(t_all *all, pid_t *pid, t_list *present);
void	ft_create_pids(t_all *all, pid_t *pid, t_list *present);
void	ft_wait_pid(t_all *all, pid_t *pid, t_list *present);
void	ft_wait_pids(t_all *all, pid_t *pid, t_list *present);

#endif