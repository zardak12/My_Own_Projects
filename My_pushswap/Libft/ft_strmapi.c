/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:21:50 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/06 18:21:51 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	n;
	char			*ret;

	if (!s || !f)
		return (NULL);
	i = 0;
	n = (unsigned int)ft_strlen(s);
	ret = ft_strnew(n);
	if (!ret)
		return (NULL);
	while (i < n)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
