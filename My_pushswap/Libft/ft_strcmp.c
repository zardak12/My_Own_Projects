/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:21:26 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/08 15:14:54 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *t_s1;
	unsigned char *t_s2;

	t_s1 = (unsigned char*)s1;
	t_s2 = (unsigned char*)s2;
	while (1)
	{
		if (*t_s1 != *t_s2)
			return (*t_s1 - *t_s2);
		if (!(*t_s1) && !(*t_s2))
			return (0);
		t_s1++;
		t_s2++;
	}
}
