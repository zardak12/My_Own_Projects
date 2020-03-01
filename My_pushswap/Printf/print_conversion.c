/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:06:34 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/14 16:57:18 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_redirect(intmax_t num, t_conversion *conv)
{
	if (ft_strchr("du", conv->type))
		print_unsigned(conv, (uintmax_t)num);
	else if (conv->type == 'o')
		print_octal(conv, (uintmax_t)num);
	else if (ft_strchr("xp", conv->type))
		print_hexadecimal(conv, (uintmax_t)num);
	else if (conv->type == 'X')
		print_hexadecimal_big(conv, (uintmax_t)num);
}

static void		print_num_conv(t_conversion *conv, va_list ap)
{
	intmax_t	num;

	conv->flag->zero = conv->precision_set ? 0 : conv->flag->zero;
	if (conv->type == 'p')
	{
		conv->modif->l = 1;
		conv->flag->oktorop = 1;
	}
	if (conv->type == 'i')
		conv->type = 'd';
	if (conv->type == 'd')
	{
		num = signed_conv(conv, ap);
		if (num < 0 && (num *= -1))
			conv->sign = '-';
		else if (conv->flag->plus)
			conv->sign = '+';
		else if (conv->flag->space)
			conv->sign = ' ';
	}
	else
		num = unsigned_conv(conv, ap);
	print_redirect(num, conv);
}

static void		print_str_conv(t_conversion *conv, va_list ap)
{
	if (conv->type == 'c')
		print_char(conv, va_arg(ap, int));
	else if (conv->type == 's')
		print_string(conv, va_arg(ap, char*));
	else if (conv->type == '%')
		print_procent(conv, '%');
	else
		print_char(conv, conv->type);
}

char			*print_conv(char *str, va_list ap)
{
	t_conversion	*conv;

	conv = init_conv(str);
	str = parse_conv(str, conv);
	if (ft_strchr("idouxXp", conv->type))
		print_num_conv(conv, ap);
	else if (ft_strchr("f", conv->type))
		print_float(ap, conv);
	else if (ft_strchr("%cs", conv->type))
		print_str_conv(conv, ap);
	free_conv(conv);
	return (str);
}
