/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:35:30 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/12 17:35:30 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcount(const char *s, char c)
{
	size_t	ret;

	if (!s)
		return (0);
	ret = 0;
	while (*s)
	{
		if (*s == c)
			ret++;
		s++;
	}
	return (ret);
}
