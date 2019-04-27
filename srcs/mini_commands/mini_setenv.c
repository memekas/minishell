/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:49:31 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/28 00:39:06 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				check_name(char *str)
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

static size_t	new_env(char **new_str, char *name, char *val)
{
	size_t	len[3];

	len[0] = ft_strlen(name);
	len[1] = ft_strlen(val);
	len[2] = len[0] + len[1] + 1;
	*new_str = (char*)malloc(sizeof(char) * (len[2] + 1));
	(*new_str)[len[2]] = '\0';
	ft_memmove(*new_str, name, len[0]);
	(*new_str)[len[0]] = '=';
	ft_memmove(*new_str + len[0] + 1, val, len[1]);
	return (len[2]);
}

void			change_env(t_list **env, char *name, char *val)
{
	t_list	*tmp;
	size_t	count;
	char	*new;

	tmp = search_env_lst(*env, name);
	if (tmp)
	{
		free(tmp->content);
		count = new_env(&new, name, val);
		tmp->content = new;
		tmp->content_size = count;
	}
	else
	{
		count = new_env(&new, name, val);
		ft_lstaddend(env, ft_lstnew(new, count + 1));
		free(new);
	}
}

void			mini_setenv(t_list **env, char **argv, size_t argc)
{
	char	*val;

	if (argc > 3)
		return (error_print("setenv", "Too many arguments."));
	else if (argc == 1)
		return (mini_env(*env));
	else if (argc == 2)
		val = NULL;
	else
		val = argv[2];
	if (!check_name(argv[1]))
		return ;
	change_env(env, argv[1], val);
}
