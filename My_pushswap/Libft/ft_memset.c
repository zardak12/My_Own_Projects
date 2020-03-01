/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:21:02 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/07 16:55:21 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *temp_s;

	temp_s = (unsigned char*)s;
	while (n--)
	{
		*temp_s = (unsigned char)c;
		temp_s++;
	}
	return (s);
}
