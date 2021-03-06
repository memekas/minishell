/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:47:12 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/26 23:12:54 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2d_del(char ***m)
{
	char	**arr;

	arr = *m;
	if (m != NULL)
	{
		while (arr && *arr)
		{
			free(*arr);
			arr++;
		}
		free(*m);
		*m = NULL;
	}
}
