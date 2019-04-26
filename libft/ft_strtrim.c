/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:54:23 by sbearded          #+#    #+#             */
/*   Updated: 2018/11/24 02:50:49 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*copy;
	int		i[3];

	if (s == NULL)
		return (NULL);
	i[0] = 0;
	while (s[i[0]] == ' ' || s[i[0]] == '\n' || s[i[0]] == '\t')
		i[0]++;
	i[1] = i[0];
	while (s[i[0] + 1])
		i[0]++;
	while (s[i[0]] == ' ' || s[i[0]] == '\n' || s[i[0]] == '\t')
		i[0]--;
	i[2] = i[0];
	copy = (char*)malloc(sizeof(char) * (i[2] - i[1] + 2));
	if (copy == NULL)
		return (NULL);
	i[0] = 0;
	while (i[0] < i[2] - i[1] + 1)
	{
		copy[i[0]] = s[i[1] + i[0]];
		i[0]++;
	}
	copy[i[0]] = '\0';
	return (copy);
}
