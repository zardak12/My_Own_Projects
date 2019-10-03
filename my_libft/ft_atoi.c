/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:54:40 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/22 19:13:50 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long long int	result;
	long long int	temp;
	int				minus;
	int				i;

	result = 0;
	minus = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	temp = 0;
	while ((str[i]) && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (temp * 10) + (str[i] - '0');
		if ((minus > 0 && result < temp) || (minus < 0 && result < temp))
			return (minus > 0 ? -1 : 0);
		temp = result;
		i++;
	}
	return (minus * result);
}
