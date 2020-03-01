/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_blank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:45:55 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/07 13:41:11 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_blank(int len, int min, char c)
{
	while (min-- > len)
		print_mem(&c, 1);
}

static void	print_left(t_conversion *conv, char *str)
{
	print_str(str);
	print_blank(ft_strlen(str), conv->width, ' ');
}

void		print_num_blank(t_conversion *conv, char *str)
{
	if (conv->flag->minus)
		return (print_left(conv, str));
	if (conv->flag->zero)
		print_blank(ft_strlen(str), conv->width, '0');
	else
		print_blank(ft_strlen(str), conv->width, ' ');
	print_str(str);
}
