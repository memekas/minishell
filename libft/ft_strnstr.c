/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:50:55 by sbearded          #+#    #+#             */
/*   Updated: 2018/11/27 20:59:30 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;

	s1 = (char*)str;
	if (*to_find == '\0')
		return (s1);
	j = 0;
	while (*s1 != '\0' && j < len)
	{
		i = 0;
		s2 = (char*)to_find;
		while (*s1 == *s2 && *s2 != '\0' && i < len - j)
		{
			s1++;
			s2++;
			i++;
		}
		if (*s2 == '\0' && i > 0)
			return (s1 - i);
		s1 = s1 - i + 1;
		j++;
	}
	return (0);
}
