/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:08:40 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/20 17:24:19 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t i;
	size_t n;

	n = 0;
	if (*need == '\0' || need == NULL)
		return ((char*)hay);
	while (hay[n] != '\0' && n < len)
	{
		i = 0;
		while (need[i] == hay[n + i] && n + i < len)
		{
			if (need[i + 1] == '\0')
			{
				return ((char*)hay + n);
			}
			i++;
		}
		n++;
	}
	return (NULL);
}
