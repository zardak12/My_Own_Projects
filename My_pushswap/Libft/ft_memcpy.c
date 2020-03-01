/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:20:56 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/06 18:20:58 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *temp_dest;
	unsigned char *temp_src;

	if (!dest && !src)
		return (NULL);
	temp_dest = (unsigned char*)dest;
	temp_src = (unsigned char*)src;
	while (n--)
	{
		*temp_dest = *temp_src;
		temp_dest++;
		temp_src++;
	}
	return (dest);
}
