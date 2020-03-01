/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:22:11 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/06 18:27:29 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ret;

	ret = ft_strnew(len);
	if (!ret || !s)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
