/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:07:36 by sbearded          #+#    #+#             */
/*   Updated: 2018/11/23 22:36:50 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*arr1;
	unsigned char	*arr2;

	i = 0;
	arr1 = (unsigned char*)s1;
	arr2 = (unsigned char*)s2;
	while (i < n)
	{
		if (arr1[i] - arr2[i] != 0)
			return (arr1[i] - arr2[i]);
		i++;
	}
	return (0);
}
