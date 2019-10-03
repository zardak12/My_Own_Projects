/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:15:49 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/20 15:54:25 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *need)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	i = 0;
	if (*need == '\0')
		return ((char*)hay);
	while (*hay)
	{
		if (*hay == need[0])
		{
			i = 1;
			while (need[i] && *(hay + i) == need[i])
			{
				i++;
			}
			if (need[i] == '\0')
				return ((char*)hay);
		}
		hay++;
	}
	return (0);
}
