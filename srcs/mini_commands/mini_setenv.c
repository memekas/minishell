/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:49:31 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/26 23:32:06 by sbearded         ###   ########.fr       */
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

static void		old_env(t_list *env, char *name, char *val)
{
	size_t	count;
	char	*new;

	free(env->content);
	count = new_env(&new, name, val);
	env->content = new;
	env->content_size = count;
}

void			mini_setenv(t_list **env, char **argv)
{
	size_t	count;
	char	*val;
	t_list	*tmp;
	char	*new;

	count = ft_2d_count(argv);
	if (count > 3)
		return (error_print("setenv", "Too many arguments."));
	else if (count == 1)
		return (mini_env(*env));
	else if (count == 2)
		val = NULL;
	else
		val = argv[2];
	if (!check_name(argv[1]))
		return ;
	tmp = search_env_lst(*env, argv[1]);
	if (tmp)
		old_env(tmp, argv[1], val);
	else
	{
		count = new_env(&new, argv[1], val);
		ft_lstaddend(env, ft_lstnew(new, count + 1));
		free(new);
	}
}
