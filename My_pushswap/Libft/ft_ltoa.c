/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:36:38 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/14 17:51:27 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mod_sign(long long *n, int *sign)
{
	if (*n < 0)
	{
		*n *= -1;
		*sign = 1;
	}
}

char		*ft_ltoa(long long n)
{
	int			len;
	long long	t;
	int			sign;
	char		*str;

	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	t = n;
	len = 2;
	sign = 0;
	mod_sign(&n, &sign);
	while (t /= 10)
		len++;
	len += sign;
	if (!(str = ft_strnew(len-- - 1)))
		return (NULL);
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
