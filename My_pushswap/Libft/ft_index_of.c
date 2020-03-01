/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:29:59 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/12 17:30:39 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_index_of(const char *s, char c, int *error)
{
	size_t n;
	size_t i;

	if (!s)
	{
		*error = 1;
		return (0);
	}
	*error = 0;
	i = 0;
	n = ft_strlen(s);
	while (i < n)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	*error = 1;
	return (0);
}
