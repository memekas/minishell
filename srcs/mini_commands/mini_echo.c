/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:48:49 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/22 18:41:27 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_echo(char **envp, char **argv)
{
	argv++;
	while (argv && *argv)
	{
		ft_putstr(get_expansion(envp, *(argv++)));
		ft_putchar(' ');
	}
	ft_putchar('\n');
}