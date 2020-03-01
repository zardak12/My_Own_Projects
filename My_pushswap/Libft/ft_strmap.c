/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:21:48 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/15 12:40:40 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	n;
	char	*ret;

	if (!s || !f)
		return (NULL);
	i = 0;
	n = ft_strlen(s);
	ret = ft_strnew(n);
	if (!ret)
		return (NULL);
	while (i < n)
	{
		ret[i] = f(s[i]);
		i++;
	}
	return (ret);
}
