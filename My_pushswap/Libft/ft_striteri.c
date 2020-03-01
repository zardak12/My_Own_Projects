/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:21:42 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/06 18:21:43 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;
	unsigned int n;

	if (!s || !f)
		return ;
	i = 0;
	n = (unsigned int)ft_strlen(s);
	while (i < n)
	{
		f(i, &s[i]);
		i++;
	}
}
