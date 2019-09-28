/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:19:22 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/05 19:19:50 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *tab;

	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	if (!(tab = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (max >= min)
	{
		tab[max - min - 1] = max - 1;
		max--;
	}
	return (tab);
}
