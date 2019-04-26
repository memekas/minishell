/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:01:08 by sbearded          #+#    #+#             */
/*   Updated: 2018/12/04 00:18:19 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	res;
	int				sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == '\n')
		str++;
	if (*str == '-')
	{
		sign = (-1);
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (res * 10 < res && sign == 1)
			return (-1);
		else if (res * 10 < res && sign == -1)
			return (0);
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}
