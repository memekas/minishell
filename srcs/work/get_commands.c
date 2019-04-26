/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:26:56 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/27 00:11:10 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	mini_exec(t_list *env, char **argv)
{
	char			**path_com;
	char			**tmp;
	DIR				*dir;
	struct dirent	*file;

	
	if (!(path_com = get_env(env, "PATH")))
		return (0);
	tmp = path_com;
	while (*path_com)
	{
		dir = opendir(*(path_com++));
		while ((file = readdir(dir)))
			if (ft_strequ(file->d_name, argv[0]))
			{
				//exec_f
				closedir(dir);
				ft_2d_del(&tmp);
				return (1);
			}
		closedir(dir);
	}
	ft_2d_del(&tmp);
	return (0);
}

static void	check_com(t_list **env, char **argv)
{
	if (ft_strequ("echo", argv[0]))
		mini_echo(argv);
	else if (ft_strequ("cd", argv[0]))
		mini_cd();
	else if (ft_strequ("env", argv[0]))
		mini_env(*env);
	else if (ft_strequ("setenv", argv[0]))
		mini_setenv(env, argv);
	else if (ft_strequ("unsetenv", argv[0]))
		mini_unsetenv(env, argv);
	else if (ft_strequ("exit", argv[0]))
		mini_exit(env);
	else
	{
		if (mini_exec(*env, argv))
			printf("YEAH!\n");
		else
			error_command_not_found(argv[0]);
	}
}

void	get_commands(t_list **env, char *str)
{
	char	**com;
	char	**argv;
	char	**tmp;

	com = ft_strsplit_multiple(str, ";");
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
