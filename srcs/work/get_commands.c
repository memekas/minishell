/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:26:56 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/08 19:12:00 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**split_argv(char *str, char *sym)
{
	char	**words;

	words = ft_strsplit_multiple(str, sym);
	return (words);
}

static char	**get_path_com(char **envp)
{
	char	*path;
	char	**path_com;

	while (envp && *envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!envp || !*envp)
		return (NULL);	
	path = *envp;
	path_com = split_argv(path + 5, ":");
	return (path_com);
}

static int	check_com(char **envp, char **argv, char *str)
{
	char			**path_com;
	char			**tmp;
	DIR				*dir;
	struct dirent	*file;

	
	if (!(path_com = get_path_com(envp)))
	{
		ft_2d_del(&path_com);
		return (0);
	}
	tmp = path_com;
	while (*path_com)
	{
		dir = opendir(*(path_com++));
		while ((file = readdir(dir)))
			if (ft_strequ(file->d_name, argv[0]))
			{
				//exec_f
				ft_2d_del(&tmp);
				return (1);
			}
	}
	ft_2d_del(&tmp);
	return (0);
}

void	get_commands(char **envp, char *str)
{
	char	**com;
	char	**argv;
	char	**tmp;

	com = split_argv(str, ";");
	tmp = com;
	while (com && *com)
	{
		argv = split_argv(str, " \t\n\0");
		if (check_com(envp, argv, *com))
			printf("YEAH!\n");
		com++;
		ft_2d_del(&argv);
	}
	ft_2d_del(&tmp);
}
