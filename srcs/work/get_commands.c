/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:26:56 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/27 22:37:35 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_com(t_list **env, char **argv)
{
	size_t	argc;

	argc = ft_2d_count(argv);
	if (ft_strequ("echo", argv[0]))
		mini_echo(argv);
	else if (ft_strequ("cd", argv[0]))
		mini_cd(env, argv, argc);
	else if (ft_strequ("env", argv[0]))
		mini_env(*env);
	else if (ft_strequ("setenv", argv[0]))
		mini_setenv(env, argv, argc);
	else if (ft_strequ("unsetenv", argv[0]))
		mini_unsetenv(env, argv, argc);
	else if (ft_strequ("exit", argv[0]))
		mini_exit(env);
	else
	{
		if (!mini_exec(*env, argv))
			error_command_not_found(argv[0]);
	}
}

void		get_commands(t_list **env, char *str)
{
	char	**com;
	char	**argv;
	char	**tmp;

	com = ft_strsplit_multiple(str, ";");
	free(str);
	tmp = com;
	while (com && *com)
	{
		argv = ft_strsplit_multiple(*com, " \t\n\0");
		if (expansion_argv(*env, argv) == -1)
			break ;
		check_com(env, argv);
		com++;
		ft_2d_del(&argv);
	}
	ft_2d_del(&tmp);
}
