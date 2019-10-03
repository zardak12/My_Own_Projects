/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:26:31 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/23 19:23:21 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*first;
	char	*second;

	first = (char*)dst;
	second = (char*)src;
	if (len == 0 || second == first)
		return (dst);
	if (second < first)
	{
		second = second + len - 1;
		first = first + len - 1;
		while (len--)
			*first-- = *second--;
	}
	else
	{
		while (len--)
			*first++ = *second++;
	}
	return (dst);
}
