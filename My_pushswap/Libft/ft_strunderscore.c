/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunderscore.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:32:18 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/15 12:45:35 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_insert_tab(char **s, size_t i, unsigned int tab_size)
{
	unsigned int k;

	k = 0;
	while (k < tab_size)
	{
		k++;
		(*s)[i++] = '_';
	}
	return (i);
}

char			*ft_strunderscore(const char *s, unsigned int tab_size)
{
	size_t	tabs;
	size_t	n;
	size_t	i;
	char	*ret;

	if (!s)
		return (NULL);
	tabs = ft_strcount(s, '\t');
	n = ft_strlen(s);
	if (!n)
		return (ft_strdup(""));
	if (!(ret = ft_strnew(tabs * tab_size + (n - tabs))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == ' ')
			ret[i++] = '_';
		else if (*s == '\t')
			i = ft_insert_tab(&ret, i, tab_size);
		else
			ret[i++] = *s;
		s++;
	}
	return (ret);
}
