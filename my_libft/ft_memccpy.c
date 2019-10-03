/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:19:50 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/22 19:27:02 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;

	first = (unsigned char*)destination;
	second = (unsigned char*)source;
	if ((destination = NULL) && (source == NULL))
		return (0);
	while (n)
	{
		*first = *second;
		if (*first == (unsigned char)c)
			return (first + 1);
		first++;
		second++;
		n--;
	}
	return (NULL);
}
