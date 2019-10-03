/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:15:48 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/22 17:01:21 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	char	*dst;

	if (s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		if (*s == '\0')
			return (ft_strdup(s));
		dst = (char*)s;
		while (*dst)
			dst++;
		while (*--dst == ' ' || *dst == '\t' || *dst == '\n')
			;
		if (!(str = (char*)malloc(dst - s + 2)))
			return (NULL);
		ft_strncpy(str, s, dst - s + 1);
		*(str + (dst - s + 1)) = '\0';
		return (str);
	}
	return (NULL);
}
