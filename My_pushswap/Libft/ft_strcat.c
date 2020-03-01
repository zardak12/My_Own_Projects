/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:21:13 by dmaxime           #+#    #+#             */
/*   Updated: 2019/09/06 18:21:15 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	char	*ret;
	int		i;

	i = 0;
	ret = dest;
	while (dest[i] != '\0')
		i++;
	while (*src != '\0')
	{
		dest[i++] = *src;
		src++;
	}
	dest[i] = '\0';
	return (ret);
}
