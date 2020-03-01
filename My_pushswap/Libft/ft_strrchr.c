/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:22:04 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/08 14:07:27 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen((char *)s);
	while (s[n] != c && n > 0)
		n--;
	if (s[n] == c)
		return ((char *)(s + n));
	return (NULL);
}
