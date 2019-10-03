/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:27:44 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/23 19:19:16 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *first;
	char *second;
	char *memmory;

	if (!s || !f)
		return (NULL);
	memmory = ft_memalloc((size_t)(ft_strlen((char*)s) + 1));
	if (*s == '\0' || memmory == NULL)
		return (NULL);
	first = (char*)s;
	second = memmory;
	while (*first)
	{
		*second = f(*(first));
		first++;
		second++;
	}
	return (memmory);
}
