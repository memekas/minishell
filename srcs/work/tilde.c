/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:39:01 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/25 14:29:18 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_tildename(char **dest, char *src)
{
	int	len;

	len = 0;
	if (*src == '+' || *src == '-')
		len++;
	else
		while (ft_isdigit(src[len]) || ft_isalpha(src[len]) || src[len] == '_')
			len++;
	if (src[len] != '/' && src[len])
		return (-1);
	*dest = (char*)malloc(sizeof(char) * (len + 1));
	(*dest)[len] = '\0';
	ft_memmove(*dest, src, len);
	return (len);
}

int		check_tildename(char *tildename, char **home)
{
	int		tail;
	char	*path;
	char	tmp;
	DIR		*dir;

	tail = 0;
	while ((*home)[tail])
		tail++;
	while((*home)[tail] != '/')
		tail--;
	tmp = (*home)[tail + 1];
	(*home)[tail + 1] = '\0';
	path = ft_strjoin(*home, tildename);
	(*home)[tail + 1] = tmp;
	dir = opendir(path);
	if (dir == NULL)
	{
		error_tilde_no_user(tildename);
		free(path);
		return (0);
	}
	*home = path;
	closedir(dir);
	return (1);
}

int	tilde_f(char **envp, char **dest)
{
	size_t	len_name;
	char	*str;
	char	*tildename;

	str = *dest;
	if (*str == '~')
		str++;
	if ((len_name = get_tildename(&tildename, str)) == -1)
		return (1);
	if (ft_strequ(tildename, "+"))
		str = search_env(envp, "PWD");
	else if (ft_strequ(tildename, "-"))
		str = search_env(envp, "OLDPWD");
	else
	{
		str = search_env(envp, "HOME");
		if (len_name > 0)
			if (check_tildename(tildename, &str) == 0)
				return (-1);
	}
	ft_strinsert(dest, 0, len_name + 1, str);
	return (1);
}