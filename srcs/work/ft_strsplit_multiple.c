/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_multiple.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:08:41 by sbearded          #+#    #+#             */
/*   Updated: 2019/05/01 18:06:01 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmp_char(char c, char *arr)
{
	while (arr && *arr)
	{
		if (c == *(arr++))
			return (1);
	}
	return (0);
}

/*static size_t	*create_word(char *word, char *str, char *check)
{
	size_t	len;
	size_t	len_a;

	len = 0;
	while (str[len])
	{
		if (!cmp_char(str[len], check))
		{
			if (str[len] == '\"')
			{
				len_a = 0;
				while (str[len + 1 + len_a] && str[len + 1 + len_a] != '\"')
					len_a++;
			}
		}
		else
			return (len);
	}
}*/

static void	create_lst_split(t_list **lst, char const *s, char *c)
{
	size_t	word_len;
	t_list	*tmp;

	while (*s)
	{
		if (cmp_char(*s, c))
			s++;
		else
		{
			word_len = 0;
			while (s[word_len] && !cmp_char(s[word_len], c))
				word_len++;
			tmp = ft_lstnew(s, word_len + 1);
			((char*)tmp->content)[word_len] = '\0';
			ft_lstaddend(lst, tmp);
			s += word_len;
		}
	}
}

static char	**create_arr_split(t_list *lst)
{
	size_t	count;
	size_t	i;
	char	**split;

	count = ft_lstcount(lst);
	split = (char**)malloc(sizeof(char*) * (count + 1));
	i = 0;
	while (i < count)
	{
		split[i] = ft_strdup(lst->content);
		lst = lst->next;
		i++;
	}
	split[i] = NULL;
	return (split);
}

char		**ft_strsplit_multiple(char const *s, char *c)
{
	t_list	*words;
	char	**split;

	words = NULL;
	create_lst_split(&words, s, c);
	split = create_arr_split(words);
	ft_lstdel(&words, ft_lstdelcontent);
	return (split);
}
