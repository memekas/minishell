/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:45:32 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/08 17:34:39 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		commands(char **envp)
{
	char	*str;

	str = wait_input();
	get_commands(envp, str);
	if (!ft_strcmp(str, "exit"))
			exit(0);
}
