/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:42:48 by sbearded          #+#    #+#             */
/*   Updated: 2018/11/27 20:43:33 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char *addr;

	addr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	if (*src == '\0')
	{
		*dest = *src;
	}
	return (addr);
}
