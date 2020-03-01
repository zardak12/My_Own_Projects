/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:22:13 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/07 16:29:16 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_has_symbols(char const *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\n' && *s != '\t')
			return (1);
		s++;
	}
	return (0);
}

static unsigned int	find_begin(char const *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			break ;
		i++;
	}
	return (i);
}

char				*ft_strtrim(char const *s)
{
	unsigned int	begin;
	unsigned int	n;
	unsigned int	i;
	char			*ret;

	if (!s)
		return (NULL);
	if (!ft_has_symbols(s))
		return (ft_strdup(""));
	n = (unsigned int)ft_strlen(s);
	begin = find_begin(s);
	i = n;
	while (i-- > 0)
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			break ;
	ret = ft_strsub(s, begin, i - begin + 1);
	return (ret);
}
