/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:47:53 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/27 20:11:05 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_err(char *path)
{
	char		*tmp;
	struct stat	*buf;

	buf = (struct stat*)malloc(sizeof(struct stat));
	if (stat(path, buf))
	{
		tmp = ft_strjoin("no such file or directory: ", path);
		error_print("cd", tmp);
	}
	else if (access(path, R_OK))
	{
		tmp = ft_strjoin("permission denied: ", path);
		error_print("cd", tmp);
	}
	else
	{
		tmp = ft_strjoin("not a directory: ", path);
		error_print("cd", tmp);
	}
	free(buf);
	free(tmp);
}

void		mini_cd(t_list **env, char **argv, size_t argc)
{
	char	buf[BUFF_PWD];
	char	*new_pwd;
	int		tmp;

	tmp = 0;
	if (argc > 2)
		return (error_print("cd", "Too many arguments."));
	else if (argc == 1)
		new_pwd = search_env(*env, "HOME");
	else
		new_pwd = argv[1];
	if (ft_strequ(new_pwd, "-"))
		new_pwd = search_env(*env, "OLDPWD");
	getcwd(buf, BUFF_PWD);
	if (new_pwd == NULL)
		return ;
	if (chdir(new_pwd))
		return (get_err(new_pwd));
	change_env(env, "OLDPWD", buf);
	change_env(env, "PWD", getcwd(buf, BUFF_PWD));
}
