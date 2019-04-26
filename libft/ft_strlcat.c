/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimir <vladimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:18:27 by sbearded          #+#    #+#             */
/*   Updated: 2018/12/03 02:19:52 by vladimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dlen;
	size_t slen;

	dlen = 0;
	slen = 0;
	while (*dest != '\0' && size > 0)
	{
		dest++;
		dlen++;
		size--;
	}
	while (*src != '\0')
	{
		if (size > 1)
		{
			*dest = *src;
			dest++;
			size--;
		}
		src++;
		slen++;
	}
	if (size != 0)
		*dest = '\0';
	return (dlen + slen);
}
