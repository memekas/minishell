/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:23:37 by sbearded          #+#    #+#             */
/*   Updated: 2018/11/27 22:53:51 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	mem = (char*)malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
