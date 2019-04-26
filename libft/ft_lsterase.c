/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsterase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 23:57:13 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/27 00:08:33 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lsterase(t_list **lst_s, void *content, size_t size)
{
	t_list	*lst;
	t_list	*prev;

	lst = *lst_s;
	prev = NULL;
	while (lst)
	{
		if (ft_memcmp(lst->content, content, size) == 0)
		{
			if (prev)
				prev->next = lst->next;
			else
				*lst_s = lst->next;
			ft_lstdelone(&lst, ft_lstdelcontent);
			return ;
		}
		prev = lst;
		lst = lst->next;
	}
}
