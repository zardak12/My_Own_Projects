/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:05:03 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/12 17:40:28 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int b, size_t len)
{
	unsigned	char *p;

	p = str;
	if (len == 0)
		return (str);
	while (len)
	{
		*p = b;
		p++;
		len--;
	}
	return (str);
}
