/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:00:29 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/23 19:19:57 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*first;
	char			*second;
	char			*memmory;

	i = 0;
	if (!s || !f)
		return (NULL);
	memmory = ft_memalloc((size_t)ft_strlen((char*)s) + 1);
	if (*s == '\0' || memmory == NULL)
		return (NULL);
	first = (char*)s;
	second = memmory;
	while (first[i])
	{
		second[i] = f(i, first[i]);
		i++;
	}
	return (second);
}
