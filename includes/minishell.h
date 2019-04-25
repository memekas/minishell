/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:35:38 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/25 16:11:42 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_C
# define MINISHELL_C

# include "libft.h"

# include <stdio.h> //удалить
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <dirent.h>

/*
** print
*/
void	print_prompt(void);

/*
** work
*/
char	*wait_input(void);
void	commands(char ***envp);
char	**ft_strsplit_multiple(char const *s, char *c);
void	get_commands(char ***envp, char *str);
char	**get_env(char **envp, char *str);
char	*search_env(char **envp, char *str);
int		expansion_argv(char **envp, char **argv);
size_t	ft_strinsert(char **dest, size_t index, size_t size, char *src);
size_t	get_dollar(char **envp, char **dest, size_t index);
int		tilde_f(char **envp, char **dest);

/*
** commands
*/
void	mini_exit();
void	mini_cd();
void	mini_echo(char **envp, char **argv);
void	mini_env(char **envp);
void	mini_setenv(char ***envp, char **argv);
void	mini_unsetenv();

/*
** free
*/
void	ft_2d_del(char ***m);

/*
** error
*/
void	error_command_not_found(char *str);
void	error_tilde_no_user(char *str);
void	error_print(char *func, char *text);

#endif