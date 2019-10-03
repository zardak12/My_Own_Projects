/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:02:18 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/22 19:47:40 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*out;

	out = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		out = (char *)malloc(sizeof(char) * (len + 1));
		if (out)
		{
			ft_strcpy(out, s1);
			ft_strcat(out, s2);
		}
	}
	return (out);
}
