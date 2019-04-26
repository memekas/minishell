/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsterase_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 00:07:35 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/27 00:08:26 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lsterase_char(t_list **lst_s, char *content)
{
	t_list	*lst;
	t_list	*prev;

	lst = *lst_s;
	prev = NULL;
	while (lst)
	{
		if (ft_strequ(lst->content, content))
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
