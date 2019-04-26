/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 00:11:45 by sbearded          #+#    #+#             */
/*   Updated: 2018/11/24 01:05:00 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_calc(int n, char *arr, int sign, int size)
{
	int	res;

	res = n % 10;
	if (res < 0)
		res *= (-1);
	arr[size - 1 + sign] = res + '0';
	if (n / 10)
		ft_itoa_calc(n / 10, arr, sign, size - 1);
}

static int	digit_count(int n)
{
	if (n / 10)
		return (1 + digit_count(n / 10));
	return (1);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		digits;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	digits = digit_count(n);
	num = (char*)malloc(sizeof(char) * (digits + sign + 1));
	if (num == NULL)
		return (NULL);
	ft_itoa_calc(n, num, sign, digits);
	if (sign == 1)
		num[0] = '-';
	num[digits + sign] = '\0';
	return (num);
}
