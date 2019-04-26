/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unsetenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:50:08 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/27 00:10:49 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_unsetenv(t_list **env, char **argv)
{
	size_t	count;
	t_list	*tmp;

	count = ft_2d_count(argv);
	if (count < 2)
		return (error_print("unsetenv", "Too few arguments."));
	argv++;
	while (argv && *argv)
	{
		tmp = search_env_lst(*env, *argv);
		if (tmp)
			ft_lsterase_char(env, tmp->content);
		argv++;
	}
}
