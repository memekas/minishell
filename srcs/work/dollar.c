/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:37:47 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/25 14:17:30 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
