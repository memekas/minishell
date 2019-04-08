/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:35:38 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/08 18:41:16 by sbearded         ###   ########.fr       */
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
void	commands(char **envp);
char	**ft_strsplit_multiple(char const *s, char *c);
void	get_commands(char **envp, char *str);

/*
** free
*/
void	ft_2d_del(char ***m);


#endif