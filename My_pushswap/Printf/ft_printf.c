/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:52:24 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/14 16:56:46 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*print_until(char *str, char c)
{
	while (*str != '\0' && *str != c)
		print_mem(str++, 1);
	return (str);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;

	va_start(ap, format);
	str = (char *)format;
	while (*str)
	{
		str = print_until(str, '%');
		if (*str == '%')
			str++;
		if (*str)
			str = print_conv(str, ap);
	}
	va_end(ap);
	return (get_result(0, 0));
}
