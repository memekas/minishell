/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:48:49 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/27 20:11:51 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_echo(char **argv)
{
	argv++;
	while (argv && *argv)
	{
		ft_putstr(*(argv++));
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
