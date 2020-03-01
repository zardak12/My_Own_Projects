/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:21:16 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/08 13:54:52 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *t_str;

	t_str = (char*)s;
	while (*t_str != c)
	{
		if (!(*t_str))
			return (NULL);
		t_str++;
	}
	return (t_str);
}
