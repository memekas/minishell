/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 22:26:57 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/28 01:28:13 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_f(char **argv)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execvp(argv[0], argv);
	else if (pid > 0)
		wait(0);
}

static int	check_com_name(char *name)
{
	struct stat		*file;
	unsigned int	x;

	file = (struct stat*)malloc(sizeof(struct stat));
	if (lstat(name, file))
	{
		free(file);
		return (0);
	}
	x = file->st_mode & S_IFMT;
	free(file);
	if (!(x == S_IFREG))
		return (0);
	if (access(name, X_OK))
		return (0);
	return (1);
}

static void	check_path_access(char *path_com, char *name, char **argv)
{
	char			*path;

	path = get_path(path_com, name);
	if (access(path, X_OK) == 0)
		exec_f(argv);
	else
		error_print(name, "permission denied");
	free(path);
}

static int	check_exec_path(t_list *env, char **argv)
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
		dir = opendir(*path_com);
		while ((file = readdir(dir)))
			if (ft_strequ(file->d_name, argv[0]))
			{
				check_path_access(*path_com, argv[0], argv);
				closedir(dir);
				ft_2d_del(&tmp);
				return (1);
			}
		closedir(dir);
		path_com++;
	}
	ft_2d_del(&tmp);
	return (0);
}

int			mini_exec(t_list *env, char **argv)
{
	if (!argv[0])
		return (1);
	if (check_com_name(argv[0]))
	{
		exec_f(argv);
		return (1);
	}
	return (check_exec_path(env, argv));
}
