/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 03:38:04 by sbearded          #+#    #+#             */
/*   Updated: 2018/11/28 00:22:28 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_lst = f(lst);
	if (new_lst == NULL)
		return (NULL);
	new_lst->next = ft_lstmap(lst->next, f);
	return (new_lst);
}
