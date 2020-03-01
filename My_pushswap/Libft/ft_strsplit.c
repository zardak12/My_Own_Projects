/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:30:28 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/15 12:45:35 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wc(char const *s, char c)
{
	int is_c;
	int count;

	if (!s)
		return (-1);
	is_c = 0;
	count = 0;
	while (*s)
	{
		if (is_c && *s == c)
			is_c = 0;
		if (!is_c && *s != c)
		{
			count++;
			is_c = 1;
		}
		s++;
	}
	return (count);
}

static void	ft_skip(char const **s, char c)
{
	while (**s && **s == c)
		(*s)++;
}

static void	ft_fill_str(char const **s, char **to_fill, char c)
{
	int n;

	n = ft_strlen_until(*s, c);
	*to_fill = ft_strnew(n);
	if (!(*to_fill))
		return ;
	while (**s != c && **s)
	{
		**to_fill = **s;
		(*s)++;
		(*to_fill)++;
	}
	*to_fill -= n;
}

static char	**ft_fallback(char ***a)
{
	char **t;

	t = *a;
	while (*t)
	{
		free(*t);
		t++;
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**head;
	char	**ret;
	int		n;

	if ((n = ft_wc(s, c)) == -1)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(*ret) * (n + 1))))
		return (NULL);
	head = ret;
	while (*s)
	{
		ft_skip(&s, c);
		if (*s)
		{
			ft_fill_str(&s, ret, c);
			if (!(*ret))
				return (ft_fallback(&head));
			ret++;
		}
		if (!(*s))
			break ;
		s++;
	}
	*ret = 0;
	return (ret - n);
}
