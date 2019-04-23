/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:31:57 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/23 17:59:58 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static char	*get_dollar(char **envp, char *src)
{
	size_t	i;
	char	*var;
	char	*env;

	if (*src == '$')
		src++;
	if (!*src)
		return ("$");
	i = 0;
	while (	ft_isalpha(src[i]) || ft_isdigit(src[i]))
		i++;
	var = (char*)malloc(sizeof(char) * (i + 1));
	var[i] = '\0';
	ft_memmove(var, src, sizeof(char) * i);
	env = search_env(envp, var);
	free(var);
	if (src[i] == '$')
		return (ft_srcjoin(env, get_dollar(envp, src + i)));
	else if (src[i])
		return (ft_srcjoin(env, src + i));
	if (env)
		return (env);
	return (NULL);
}

char	*get_expansion(char **envp, char *src)
{
	if (*src == '$')
		return (get_dollar(envp, src));
	else if (*src == '~')
		;
	else
		return (ft_srcdup(src));
}*/

size_t	get_envname(char **dest, char *src)
{
	size_t	len;

	len = 0;
	if (ft_isdigit(*src))
		while (ft_isdigit(src[len]))
			len++;
	else
		while (ft_isdigit(src[len]) || ft_isalpha(src[len]) || src[len] == '_')
			len++;
	*dest = (char*)malloc(sizeof(char) * (len + 1));
	(*dest)[len] = '\0';
	ft_memmove(*dest, src, len);
	return (len);
}

size_t	get_dollar(char **envp, char **dest, size_t index)
{
	size_t	len_name;
	char	*src;
	char	*name;
	char	*env;

	src = (*dest) + index;
	if (*src == '$')
		src++;
	else
		return (1);
	if (!*src)
		return (1);
	len_name = get_envname(&name, src);
	if (!*name)
	{
		free(name);
		return (1);
	}
	env = search_env(envp, name);
	free(name);
	return (ft_strinsert(dest, index, len_name + 1, env));
}

void	tilde_f(void)
{
	;
}

void	expansion_argv(char **envp, char **argv)
{
	size_t	i;

	while (argv && *argv)
	{
		i = 0;
		if ((*argv)[i] == '~')
			tilde_f();
		else
			while ((*argv)[i])
				if ((*argv)[i] == '$')
					i += get_dollar(envp, argv, i);
				else
					i++;
		argv++;
	}
}
