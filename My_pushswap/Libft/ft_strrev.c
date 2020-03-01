/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:37:54 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/15 12:45:35 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	char	*ret;
	size_t	n;
	size_t	i;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (!(ret = ft_strnew(n)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[n - 1 - i] = s[i];
		i++;
	}
	return (ret);
}
