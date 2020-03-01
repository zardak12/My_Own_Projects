/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:20:00 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/14 16:55:22 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_unsigned(t_conversion *conv, uintmax_t n)
{
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	if (n > 0 || !conv->precision_set)
		str[--i] = '0' + (n % 10);
	while ((n /= 10) > 0)
		str[--i] = '0' + (n % 10);
	if (conv->precision > 99 - i)
		conv->flag->zero = 0;
	while (conv->precision > 99 - i)
		str[--i] = '0';
	if (conv->flag->zero && conv->sign)
	{
		print_mem(&(conv->sign), 1);
		conv->width--;
	}
	else if (conv->sign)
		str[--i] = conv->sign;
	print_num_blank(conv, str + i);
}

void		print_octal(t_conversion *conv, uintmax_t n)
{
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	if (n > 0 || !conv->precision_set)
		str[--i] = '0' + (n % 8);
	while ((n /= 8) > 0)
		str[--i] = '0' + (n % 8);
	if (conv->flag->oktorop && str[i] != '0')
		str[--i] = '0';
	while (conv->precision > 99 - i)
		str[--i] = '0';
	print_num_blank(conv, str + i);
}

void		print_hexadecimal(t_conversion *conv, uintmax_t n)
{
	char		str[100];
	int			i;
	uintmax_t	tn;

	tn = n;
	i = 99;
	str[i] = '\0';
	if (n > 0 || !conv->precision_set)
		str[--i] = (((n % 16) <= 9) ? ('0' + (n % 16))
			: ('0' + (n % 16) + 39));
	while ((n /= 16) > 0)
		str[--i] = (((n % 16) <= 9) ? ('0' + (n % 16))
			: ('0' + (n % 16) + 39));
	while (conv->precision > 99 - i)
		str[--i] = '0';
	if (conv->flag->zero && ((conv->flag->oktorop && i < 99 && str[98] != '0')
		|| conv->type == 'p') && print_mem("0x", 2))
		conv->width -= 2;
	else if ((conv->flag->oktorop && i < 99 && (str[98] != '0' || tn))
		|| conv->type == 'p')
	{
		str[--i] = 'x';
		str[--i] = '0';
	}
	print_num_blank(conv, str + i);
}

static void	width_print(int *width)
{
	*width -= 2;
	print_mem("0X", 2);
}

void		print_hexadecimal_big(t_conversion *conv, uintmax_t n)
{
	char	str[100];
	int		i;
	int		tn;

	tn = n;
	i = 99;
	str[i] = '\0';
	if (n > 0 || !conv->precision_set)
		str[--i] = (((n % 16) <= 9) ? ('0' + (n % 16))
			: ('0' + (n % 16) + 7));
	while ((n /= 16) > 0)
		str[--i] = (((n % 16) <= 9) ? ('0' + (n % 16))
			: ('0' + (n % 16) + 7));
	while (conv->precision > 99 - i)
		str[--i] = '0';
	if (conv->flag->zero && conv->flag->oktorop
		&& str[i] != '0' && (tn || conv->precision))
		width_print(&conv->width);
	else if (conv->flag->oktorop &&
		(str[i] != '0' || tn) && (tn || conv->precision))
	{
		str[--i] = 'X';
		str[--i] = '0';
	}
	print_num_blank(conv, str + i);
}
