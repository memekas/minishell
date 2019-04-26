/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:08:41 by sbearded          #+#    #+#             */
/*   Updated: 2018/11/30 22:56:48 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*write_word(char const *s, char c, char *split)
{
	while (*s == (char)c)
		s++;
	while (*s != (char)c && *s)
	{
		*split = *s;
		s++;
		split++;
	}
	*split = '\0';
	return (s);
}

static int			get_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s == (char)c)
		s++;
	while (*s != (char)c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static int			words_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != (char)c)
		{
			i++;
			while (*s != (char)c && *s)
				s++;
			if (!*s)
				return (i);
		}
		s++;
	}
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		word;
	int		i;

	if (s == NULL)
		return (NULL);
	word = words_count(s, c);
	split = (char**)malloc(sizeof(char*) * (word + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < word)
	{
		split[i] = (char*)malloc(sizeof(char) * (get_word_len(s, c) + 1));
		if (split[i] == NULL)
		{
			ft_2d_del(&split);
			return (NULL);
		}
		s = write_word(s, c, split[i]);
		i++;
	}
	split[i] = (char*)malloc(sizeof(char));
	split[i] = NULL;
	return (split);
}
