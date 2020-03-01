/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:21:53 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/07 18:45:33 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	ret = dest;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		if (len == j)
			break ;
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ret);
}
