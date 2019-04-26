/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:48:49 by sbearded          #+#    #+#             */
/*   Updated: 2018/11/24 02:42:02 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new_s;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	new_s = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		new_s[i] = f(*s);
		s++;
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
