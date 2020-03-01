/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:49:42 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/07 13:40:44 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_flags(char *str, t_flag *flag)
{
	while (ft_strchr("#0-+ ", *str))
	{
		if (*str == '#')
			flag->oktorop = 1;
		else if (*str == '0')
			flag->zero = 1;
		else if (*str == '-')
			flag->minus = 1;
		else if (*str == '+')
			flag->plus = 1;
		else if (*str == ' ')
			flag->space = 1;
		else if (!(*str))
			break ;
		else
			error("We haven't got flags.\n");
		str++;
	}
	if (!str)
		error("Invalid format.\n");
	return (str);
}

char	*parse_width(char *str, t_conversion *conv)
{
	conv->width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (!str)
		error("Invalid format.\n");
	return (str);
}

char	*parse_precision(char *str, t_conversion *conv)
{
	if (*str != '.')
		return (str);
	str++;
	conv->precision = ft_atoi(str);
	conv->precision_set = 1;
	while (ft_isdigit(*str))
		str++;
	if (!str)
		error("Invalid format.\n");
	return (str);
}

char	*parse_modificator(char *str, t_modif *modif)
{
	if (!ft_strchr("Lhl", *str))
		return (str);
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		modif->hh = 1;
		return (str + 2);
	}
	if (ft_strncmp(str, "ll", 2) == 0)
	{
		modif->ll = 1;
		return (str + 2);
	}
	else if (*str == 'h')
		modif->h = 1;
	else if (*str == 'l')
		modif->l = 1;
	else if (*str == 'L')
		modif->big_l = 1;
	return (str + 1);
}

char	*parse_conv(char *str, t_conversion *conv)
{
	str = parse_flags(str, conv->flag);
	if (!str)
		error("Invalid format.\n");
	str = parse_width(str, conv);
	str = parse_precision(str, conv);
	str = parse_modificator(str, conv->modif);
	if (!str)
		error("Invalid format. (After Modifier)\n");
	conv->type = *str;
	return (str + 1);
}
