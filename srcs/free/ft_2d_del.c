/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:47:12 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/08 19:08:04 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_2d_del(char ***m)
{
	char	**x;

	x = *m;
	if (m)
	{
		while (x && *x)
			free(*(x++));
		free(*m);
	}
}