/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:31:57 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/25 14:22:16 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expansion_argv(char **envp, char **argv)
{
	size_t	i;

	while (argv && *argv)
	{
		i = 0;
		while ((*argv)[i])
			if ((*argv)[i] == '$')
				i += get_dollar(envp, argv, i);
			else
				i++;
		if ((*argv)[0] == '~')
				if (tilde_f(envp, argv) == -1)
					return (-1);
		argv++;
	}
	return (1);
}
