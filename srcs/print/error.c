/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:35:35 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/25 16:12:52 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_command_not_found(char *str)
{
	ft_putstr_fd("mini: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	error_tilde_no_user(char *str)
{
	ft_putstr_fd("mini: no such user or named directory: ", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
}

void	error_print(char *func, char *text)
{
	ft_putstr_fd("mini: ", 2);
	ft_putstr_fd(func, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putchar_fd('\n', 2);
}
