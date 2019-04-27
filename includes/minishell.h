/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:35:38 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/28 00:09:45 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>

# define BUFF_PWD	500

/*
** print
*/
void	print_prompt(void);

/*
** work
*/
t_list	*create_env_lst(char **envp);
char	*wait_input(void);
void	commands(t_list **env);
char	**ft_strsplit_multiple(char const *s, char *c);
void	get_commands(t_list **env, char *str);
char	**get_env(t_list *env, char *str);
char	*search_env(t_list *env, char *str);
t_list	*search_env_lst(t_list *env, char *str);
void	change_env(t_list **env, char *name, char *val);
int		expansion_argv(t_list *env, char **argv);
size_t	ft_strinsert(char **dest, size_t index, size_t size, char *src);
size_t	get_dollar(t_list *env, char **dest, size_t index);
int		tilde_f(t_list *env, char **dest);

/*
** commands
*/
void	mini_exit(t_list **env);
void	mini_cd(t_list **env, char **argv, size_t argc);
void	mini_echo(char **argv);
void	mini_env(t_list *env);
void	mini_setenv(t_list **env, char **argv, size_t argc);
void	mini_unsetenv(t_list **env, char **argv, size_t argc);
int		mini_exec(t_list *env, char **argv);

/*
** error
*/
void	error_command_not_found(char *str);
void	error_tilde_no_user(char *str);
void	error_print(char *func, char *text);

#endif
