/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:03:23 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/20 16:03:30 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int str, size_t len)
{
	char			*real;

	if (!s || !(real = ft_memalloc(len + 1)))
		return (NULL);
	real = ft_strncpy(real, (char*)s + str, len);
	return (real);
}
