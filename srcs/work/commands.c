/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:45:32 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/08 16:38:53 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	run_command(char *str)
{
	char	**words;

	words = ft_strsplit_multiple(str, " \t\n\0");
	printf("command: \n");
	while(words && *words)
		printf("%s\n", *(words++));
	printf("next\n");
}

static void	split_commands(char *str)
{
	char	**words;

	words = ft_strsplit(str, ';');
	while(words && *words)
		run_command(*(words++));
}

void		commands(char **envp)
{
	char	*str;

	str = wait_input();
	split_commands(str);
	if (!ft_strcmp(str, "exit"))
			exit(0);
}
