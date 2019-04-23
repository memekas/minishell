/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:47:29 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/23 17:53:44 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strinsert(char **dest, size_t index, size_t size, char *src)
{
	char	*tail;
	char	*new_str;
	size_t	len_src;
	size_t	len_tail;
	size_t	len_newstr;

	tail = *dest + index + size;
	len_tail = ft_strlen(tail);
	len_src = 0;
	while (src && src[len_src])
		len_src++;
	len_newstr = index + len_src + len_tail;
	new_str = (char*)malloc(sizeof(char) * (len_newstr + 1));
	new_str[len_newstr] = '\0';
	ft_memmove(new_str, *dest, index);
	ft_memmove(new_str + index, src, len_src);
	ft_memmove(new_str + index + len_src, tail, len_tail);
	free(*dest);
	*dest = new_str;
	return (len_src);
}
