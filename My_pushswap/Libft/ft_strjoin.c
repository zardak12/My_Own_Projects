/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:21:44 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/15 12:45:35 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	size_t	n;
	size_t	tn;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	tn = ft_strlen(s1);
	n = tn + ft_strlen(s2);
	if (!(ret = ft_strnew(n)))
		return (NULL);
	i = 0;
	while (i < tn)
	{
		ret[i] = s1[i];
		i++;
	}
	k = 0;
	while (k + i < n)
	{
		ret[i + k] = s2[k];
		k++;
	}
	return (ret);
}
