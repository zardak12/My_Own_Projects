/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:20:55 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/07 13:40:16 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	*new_flags(void)
{
	t_flag		*flag;

	flag = malloc(sizeof(t_flag));
	ft_bzero(flag, sizeof(t_flag));
	return (flag);
}

static t_modif	*new_modif(void)
{
	t_modif		*modif;

	modif = malloc(sizeof(t_modif));
	ft_bzero(modif, sizeof(t_modif));
	return (modif);
}

t_conversion	*init_conv(char *str)
{
	t_conversion	*conv;

	conv = malloc(sizeof(t_conversion));
	ft_bzero(conv, sizeof(t_conversion));
	conv->start = str;
	conv->flag = new_flags();
	conv->modif = new_modif();
	return (conv);
}
