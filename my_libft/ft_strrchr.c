/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:17:12 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/16 15:29:25 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*value;

	value = (0);
	while (*s)
	{
		if (*s == c)
			value = (char*)s;
		s++;
	}
	if (value)
		return (value);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
