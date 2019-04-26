/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:50:46 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/26 20:22:43 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*search_env_lst(t_list *env, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	while (env)
	{
		if (ft_strncmp(env->content, str, len) == 0)
			if (((char*)env->content)[len] == '=')
				break ;
		env = env->next;
	}
	if (!env)
		return (NULL);
	return (env);
}

char	*search_env(t_list *env, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	while (env)
	{
		if (ft_strncmp(env->content, str, len) == 0)
			if (((char*)env->content)[len] == '=')
				break ;
		env = env->next;
	}
	if (!env)
		return (NULL);
	return (env->content + len + 1);
}

char	**get_env(t_list *env, char *str)
{
	char	*path;
	char	**path_com;

	path = search_env(env, str);
	path_com = ft_strsplit_multiple(path, ":");
	return (path_com);
}

t_list	*create_env_lst(char **envp)
{
	t_list	*new;

	new = NULL;
	while (envp && *envp)
	{
		ft_lstaddend(&new, ft_lstnew(*envp, ft_strlen(*envp) + 1));
		envp++;
	}
	return (new);
}
