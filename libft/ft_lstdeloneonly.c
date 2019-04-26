/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeloneonly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:02:22 by sbearded          #+#    #+#             */
/*   Updated: 2018/12/05 02:51:04 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeloneonly(t_list **alst)
{
	if (alst != NULL)
	{
		if (*alst != NULL)
		{
			free(*alst);
			*alst = NULL;
		}
	}
}
