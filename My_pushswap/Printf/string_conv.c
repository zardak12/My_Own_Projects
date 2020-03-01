/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:30:15 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/07 13:48:12 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_out(t_conversion *conv, char *str, int size)
{
	if (conv->type == 's' && conv->precision_set)
		if (size >= conv->precision)
			size = conv->precision;
	if (conv->flag->minus)
	{
		print_mem(str, size);
		print_blank(size, conv->width, ' ');
		return ;
	}
	if (conv->flag->zero)
		print_blank(size, conv->width, '0');
	else
		print_blank(size, conv->width, ' ');
	print_mem(str, size);
}

void			print_char(t_conversion *conv, char c)
{
	print_out(conv, &c, 1);
}

void			print_string(t_conversion *conv, char *str)
{
	if (!str)
		str = "(null)";
	print_out(conv, str, ft_strlen(str));
}

void			print_procent(t_conversion *conv, char c)
{
	print_out(conv, &c, 1);
}
