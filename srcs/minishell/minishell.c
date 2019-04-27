/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:34:53 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/27 16:46:40 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*g_pwd;

int		main(int argc, char **argv, char **envp)
{
	t_list	*env;

	env = create_env_lst(envp);
	while (1)
	{
		print_prompt();
		commands(&env);
	}
}
