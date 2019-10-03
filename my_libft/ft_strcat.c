/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:34:38 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/12 18:07:17 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
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
	while (second[j])
	{
		first[i] = second[j];
		i++;
		j++;
	}
	first[i] = '\0';
	return (first);
}
