/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:49:31 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/25 17:17:09 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	argc_count(char **argv)
{
	int	len = 0;

	while (argv && *argv)
	{
		len++;
		argv++;
	}
	return (len);
}

int		check_name(char *str)
{
	if (!ft_isalpha(*str) && *str != '_')
	{
		error_print("setenv", "Variable name must begin with a letter.");
		return (0);
	}
	str++;
	while (str && *str)
	{
		if (!ft_isalpha(*str) && !ft_isdigit(*str) && *str != '_')
		{
			error_print("setenv",
			"Variable name must contain alphanumeric characters.");
			return (0);
		}
		str++;
	}
	return (1);
}

static void	env_copy(char **dest, char **src)
{
	int	i;

	i = -1;
	while (src && src[++i])
		dest[i] = src[i];
	dest[i] = ft_strdup("\0");
}

char	**env_realloc(char **envp, int sign, char *str)
{
	static int	max_size = 30;
	static int	size = 0;
	char		**new;

	if (size == 0)
	{
		new = (char**)malloc(sizeof(char*) * (max_size + 1));
		env_copy(new, envp);
		size = argc_count(envp);
	}
	if (sign == 1)
		size++;
	else if (sign == -1)
		size--;
	if (size > max_size)
	{
		max_size *= 2;
		new = (char**)malloc(sizeof(char*) * (max_size + 1));
	}
	else
		new = envp;
	if (sign == 1)

	return (envp);
}

void	mini_setenv(char ***envp, char **argv)
{
	char	*new;
	int		count;
	int		len_var;
	int		len_name;
	
	count = argc_count(argv);
	if (count > 3)
		return (error_print("setenv", "Too many arguments."));
	else if (count == 1)
		return (mini_env(*envp));
	else if (count == 2)
		len_var = 0;
	else
		len_var = ft_strlen(argv[2]);
	if (check_name(argv[1]) == 0)
		return ;
	len_name = ft_strlen(argv[1]);
	new = (char*)malloc(sizeof(char) * (len_name + len_var + 2));
	new[len_name + len_var + 1] = '\0';
	ft_memmove(new, argv[1], len_name);
	new[len_name] = '=';
	ft_memmove(new + len_name + 1, argv[2], len_var);
	*envp = env_realloc(*envp, 1);
}
