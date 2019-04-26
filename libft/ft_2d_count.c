/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:56:45 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/26 19:58:01 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_2d_count(char **str)
{
	size_t	count;

	count = 0;
	while (str && *str)
	{
		count++;
		str++;
	}
	return (count);
}
