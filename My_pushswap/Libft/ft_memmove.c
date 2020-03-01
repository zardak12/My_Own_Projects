/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:25:52 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/08 14:46:15 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*t_src;
	char	*t_dst;

	if (!dst && !src)
		return (NULL);
	t_src = (char*)src;
	t_dst = (char*)dst;
	i = 0;
	if (t_src < t_dst)
		while ((int)(--len) >= 0)
			*(t_dst + len) = *(t_src + len);
	else
		while (i < len)
		{
			*(t_dst + i) = *(t_src + i);
			i++;
		}
	return (dst);
}
