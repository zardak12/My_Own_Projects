/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:24:41 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/08 12:24:42 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] && len < n)
		len++;
	i = len;
	while (src[len - i] && len + 1 < n)
	{
		dst[len] = src[len - i];
		len++;
	}
	if (i < n)
		dst[len] = '\0';
	return (ft_strlen(src) + i);
}
