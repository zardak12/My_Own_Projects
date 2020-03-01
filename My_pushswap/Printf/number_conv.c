/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:51:27 by dmaxime           #+#    #+#             */
/*   Updated: 2020/01/21 13:48:01 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	signed_conv(t_conversion *conv, va_list ap)
{
	if (conv->modif->hh)
		return ((char)va_arg(ap, int));
	if (conv->modif->h)
		return ((short)va_arg(ap, int));
	if (conv->modif->l)
		return (va_arg(ap, long));
	if (conv->modif->ll)
		return (va_arg(ap, long long));
	return (va_arg(ap, int));
}

uintmax_t	unsigned_conv(t_conversion *conv, va_list ap)
{
	if (conv->modif->hh)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (conv->modif->h)
		return ((unsigned short)va_arg(ap, unsigned int));
	if (conv->modif->l)
		return (va_arg(ap, unsigned long));
	if (conv->modif->ll)
		return (va_arg(ap, unsigned long long));
	return (va_arg(ap, unsigned int));
}
