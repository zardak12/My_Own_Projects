/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:02:14 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/22 17:29:31 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long n)
{
	int size;

	size = 0;
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size + 1);
}

static long	return_long(int n)
{
	long return_value;

	return_value = (long)n;
	if (n < 0)
		return_value = -return_value;
	return (return_value);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		sign;
	long	num;

	sign = 0;
	length = ((n < 0) ? 1 : 0);
	if (n < 0)
		sign = 1;
	num = return_long(n);
	length += get_size(num);
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	str[length] = '\0';
	while (num > 9)
	{
		str[--length] = num % 10 + '0';
		num = num / 10;
	}
	str[--length] = num + '0';
	if (sign)
		str[--length] = '-';
	return (str);
}
