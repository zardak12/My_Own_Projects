/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:22:09 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/08 15:50:24 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	c;
	size_t	i;
	char	*t_hay;
	char	*t_nee;

	t_hay = (char*)haystack;
	t_nee = (char*)needle;
	c = 0;
	if (!ft_strcmp(t_nee, ""))
		return (t_hay);
	while (t_hay[c])
	{
		if (t_nee[0] == t_hay[c])
		{
			i = 1;
			while (t_nee[i] && t_nee[i] == t_hay[c + i])
				i++;
			if (!t_nee[i])
				return ((t_hay + c));
		}
		++c;
	}
	return (NULL);
}
