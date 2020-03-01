/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:51:45 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/07 16:39:54 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst)
	{
		ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}
