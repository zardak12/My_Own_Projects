/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:55:25 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/12 18:06:37 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	char		*first;
	const char	*second;
	size_t		i;
	size_t		j;

	first = dst;
	second = src;
	i = 0;
	j = 0;
	while (first[i])
		i++;
	while ((second[j]) && (j < len))
	{
		first[i] = second[j];
		i++;
		j++;
	}
	first[i] = '\0';
	return (first);
}
