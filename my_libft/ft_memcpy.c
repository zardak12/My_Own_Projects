/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:29:10 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/22 19:26:35 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;

	if (dst == NULL && src == NULL)
		return (NULL);
	first = (unsigned char*)dst;
	second = (unsigned char*)src;
	while (n)
	{
		*first = *second;
		first++;
		second++;
		n--;
	}
	return (dst);
}
