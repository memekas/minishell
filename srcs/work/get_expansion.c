/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:31:57 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/22 19:09:48 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_dollar(char **envp, char *str)
{
	size_t	i;
	char	*var;
	char	*env;

	if (!*(++str))
		return ("$");
	i = 0;
	while (	ft_isalpha(str[i]) || ft_isdigit(str[i]))
		i++;
	var = (char*)malloc(sizeof(char) * (i + 1));
	var[i] = '\0';
	ft_memmove(var, str, sizeof(char) * i);
	env = search_env(envp, var);
	free(var);
	if (str[i] == '$')
		return (ft_strjoin(env, get_dollar(envp, str + i)));
	else if (str[i])
		return (ft_strjoin(env, str + i));
	if (env)
		return (env);
	return (NULL);
}

char	*get_expansion(char **envp, char *str)
{
	if (*str == '$')
		return (get_dollar(envp, str));
	else if (*str == '~')
		;
	else
		return (ft_strdup(str));
}
