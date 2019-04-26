/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 16:54:58 by sbearded          #+#    #+#             */
/*   Updated: 2018/11/27 20:59:26 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	char	*s1;
	char	*s2;

	s1 = (char*)str;
	if (*to_find == '\0')
		return (s1);
	while (*s1 != '\0')
	{
		i = 0;
		s2 = (char*)to_find;
		while (*s1 == *s2 && *s2 != '\0')
		{
			s1++;
			s2++;
			i++;
		}
		if (*s2 == '\0' && i > 0)
			return (s1 - i);
		s1 = s1 - i + 1;
	}
	return (0);
}
