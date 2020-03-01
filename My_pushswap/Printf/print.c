/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:03:57 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/07 13:47:57 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_result(int size, int to_add)
{
	static int	total = 0;

	if (to_add)
		total += size;
	else
	{
		size = total;
		total = 0;
		return (size);
	}
	return (total);
}

int		print_mem(void *mem, int size)
{
	char	*str;
	int		i;

	str = mem;
	i = 0;
	while (i < size)
	{
		write(1, str + i, 1);
		get_result(1, 1);
		i++;
	}
	return (1);
}

void	print_str(char *str)
{
	print_mem(str, ft_strlen(str));
}
