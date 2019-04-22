/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:50:46 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/22 18:36:39 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_env(char **envp, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	while (envp && *envp)
	{
		if (ft_strncmp(*envp, str, len) == 0)
			if (*(*envp + len) == '=')
				break ;
		envp++;
	}
	if (!envp || !*envp)
		return (NULL);
	return (*envp + len + 1);
}

char	**get_env(char **envp, char *str)
{
	char	*path;
	char	**path_com;

	path = search_env(envp, str);
	path_com = ft_strsplit_multiple(path, ":");
	return (path_com);
}
