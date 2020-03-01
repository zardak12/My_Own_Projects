/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:31:17 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/14 17:52:06 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nth(long double num, int n)
{
	static int	ret;

	if (n >= 0)
	{
		ret = -1;
		while (n > 0 && num > 0)
		{
			num -= (int)num;
			num *= 10;
			ret = (int)num;
			n--;
		}
		if (num > 0)
			ret = -1;
	}
	return (ret);
}

static int	backshift(char *str, int pos)
{
	if (!pos)
		return (-1);
	else if (str[pos - 1] == '.')
		return (pos - 2);
	else
		return (pos - 1);
}

static char	*rounded(char *str, int a, int pos)
{
	if (a > 5)
	{
		if (str[pos] == '9')
		{
			str[pos] = '0';
			return (rounded(str, str[pos], backshift(str, pos)));
		}
		else
			return (replaced(str, pos, str[pos] - '0' + 1));
	}
	else if (a == 5)
	{
		if ((str[pos] - '0') % 2 == 1)
		{
			if (str[pos] == '9')
			{
				str[pos] = '0';
				return (rounded(str, str[pos], backshift(str, pos)));
			}
			else
				return (replaced(str, pos, str[pos] - '0' + 1));
		}
	}
	return (str);
}

static void	integerpart(long double x, t_conversion *conv, char *str, int pos)
{
	int			a;
	char		b;
	char		*newstr;
	long double	tx;

	tx = x;
	while (x > 0 && conv->precision > 0)
	{
		a = (int)x;
		b = a + '0';
		x -= a;
		x *= 10;
		conv->precision--;
		str[pos++] = b;
	}
	str[ft_strlen(str)] = 0;
	newstr = rounded(str, (int)x, ft_strlen(str) - 1);
	print_num_blank(conv, newstr);
	while (conv->precision > 0)
	{
		conv->precision--;
		print_str("0");
	}
	free(str);
}

void		print_long_float(long double num, t_conversion *conv)
{
	char	*b;
	char	*str;

	if (big_chk(num, conv))
		return ;
	if ((double)INT_MIN != num && num < 0 && (num *= -1))
		conv->sign = '-';
	else if (conv->flag->plus)
		conv->sign = '+';
	else if (conv->flag->space)
		conv->sign = ' ';
	sign_chk(&conv);
	str = ft_strnew(count_digit((int)num) + conv->precision);
	if (conv->precision == 0 && !conv->precision_set)
		conv->precision = 6;
	nth(num, conv->precision);
	b = ft_ltoa((long long)num);
	ft_strcat(str, b);
	if (conv->precision || conv->flag->oktorop)
		str[ft_strlen(b)] = '.';
	num -= (long long)num;
	num *= 10;
	integerpart(num, conv, str, ft_strlen(b) + 1);
	free(b);
}
