/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rindex_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:28:53 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/12 17:28:53 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_rindex_of(const char *s, char c, int *error)
{
	size_t	i;

	if (!s)
	{
		*error = 1;
		return (0);
	}
	*error = 0;
	i = ft_strlen(s);
	while (i-- > 0)
		if (s[i] == c)
			return (i);
	*error = 1;
	return (0);
}
