/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:19:58 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/08 15:38:17 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	temp_src = (unsigned char*)src;
	temp_dest = (unsigned char*)dest;
	i = 0;
	while (i < size)
	{
		temp_dest[i] = temp_src[i];
		if (temp_src[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
