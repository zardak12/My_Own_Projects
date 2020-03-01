/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:20:24 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/08 13:38:04 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp_s;
	unsigned char	ch;

	ch = (unsigned char)c;
	temp_s = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (ch == temp_s[i])
			return (void*)(temp_s + i);
		i++;
	}
	return (NULL);
}
