/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:33:15 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/07 13:39:48 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_float(va_list ap, t_conversion *conv)
{
	if (conv->modif->big_l == 1)
		print_long_float(va_arg(ap, long double), conv);
	else
		print_long_float(va_arg(ap, double), conv);
}
