/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:34:53 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/28 00:38:25 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_interrupt(int sign)
{
	sign++;
	ft_putchar('\n');
	print_prompt();
}

int			main(int argc, char **argv, char **envp)
{
	t_list	*env;

	argc++;
	argv++;
	env = create_env_lst(envp);
	while (1)
	{
		signal(SIGINT, ft_interrupt);
		print_prompt();
		commands(&env);
	}
}
