/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:27:02 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/23 20:04:59 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_free(char **ar, size_t b)
{
	if (b == 0)
		return ;
	while (--b)
		ft_strdel(&ar[b]);
	free(ar);
	ar = NULL;
}

static size_t		ft_length(char const *s, char c, size_t *n)
{
	size_t		len;

	len = 0;
	while (*(s + *n) && *(s + *n) == c)
		*n = *n + 1;
	while (*(s + *n) && *(s + *n) != c)
	{
		len++;
		*n = *n + 1;
	}
	return (len);
}

static size_t		ft_size(char const *s, char c)
{
	size_t		size;

	size = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			if (*s == '\0' || *s == c)
				size++;
		}
	}
	return (size);
}

static void			ft_make_split(char const *s, char **ar, char c)
{
	size_t		i;
	size_t		k;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			k = 0;
			while (*s && *s != c)
				ar[i][k++] = *s++;
			i++;
		}
	}
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	size;
	size_t	n;
	size_t	i;
	char	**ar;

	if (!s || !c)
		return (NULL);
	i = 0;
	size = ft_size(s, c);
	if (!(ar = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	n = 0;
	while (i < size)
		if (!(ar[i] = ft_strnew(ft_length(s, c, &n))))
		{
			ft_free(ar, i);
		}
		else
			i++;
	ar[i] = NULL;
	ft_make_split(s, ar, c);
	return (ar);
}
