/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:31:57 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/27 20:12:56 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expansion_argv(t_list *env, char **argv)
{
	size_t	i;

	while (argv && *argv)
	{
		i = 0;
		while ((*argv)[i])
			if ((*argv)[i] == '$')
				i += get_dollar(env, argv, i);
			else
				i++;
		if ((*argv)[0] == '~')
			if (tilde_f(env, argv) == -1)
				return (-1);
		argv++;
	}
	return (1);
}
