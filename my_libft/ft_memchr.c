/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:59:04 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/13 19:00:34 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char *first;
	unsigned char second;

	first = (unsigned char*)s;
	second = (unsigned char)c;
	while (len--)
	{
		if (*first == second)
			return (first);
		first++;
	}
	return (NULL);
}
