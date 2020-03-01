/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:18:26 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/14 17:12:25 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*replaced(char *str, int pos, int t)
{
	str[pos] = t + '0';
	return (str);
}

uintmax_t	count_digit(uintmax_t n)
{
	uintmax_t	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int			big_chk(long double num, t_conversion *conv)
{
	char	ch;
	char	*b;

	if (num == (double)INT_MAX + 1)
	{
		print_num_blank(conv, "2147483648.000000");
		return (1);
	}
	if (num == (double)INT_MIN - 1)
	{
		b = "2147483649.000000";
		ch = '-';
		print_mem(&ch, 1);
		print_num_blank(conv, b);
		return (1);
	}
	return (0);
}

void		sign_chk(t_conversion **conv)
{
	t_conversion	*tconv;

	tconv = *conv;
	if (tconv->sign)
	{
		tconv->width--;
		print_mem(&tconv->sign, 1);
	}
}
