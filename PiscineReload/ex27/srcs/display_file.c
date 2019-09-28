/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:24:01 by kosgrey           #+#    #+#             */
/*   Updated: 2019/09/07 16:09:36 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	display(char *name)
{
	int		file;
	char	word;

	file = open(name, O_RDONLY);
	if (file < 0)
		return ;
	while (read(file, &word, 1))
	{
		ft_putchar(word);
	}
	close(file);
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
		display(argv[1]);
	return (0);
}
