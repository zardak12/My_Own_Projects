/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosgrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:27:13 by kosgrey           #+#    #+#             */
/*   Updated: 2019/10/17 19:29:31 by kosgrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*main_action(char **buf)
{
	char	*ptr;
	char	*temp;
	int		i;
	int		len;

	len = 0;
	if (*buf)
		len = ft_strlen(*buf);
	temp = ft_memchr(*buf, '\n', len);
	i = temp - *buf;
	if ((ptr = (char *)malloc(sizeof(char) * (i + 1))))
	{
		ft_memcpy(ptr, *buf, i);
		ptr[i] = '\0';
		temp = *buf;
		*buf = ft_strsub(*buf, i + 1, len);
		free(temp);
		return (ptr);
	}
	return (NULL);
}

static int	check_lines(char **buf, char **line, int fd, int res)
{
	if (ft_strchr(buf[fd], '\n'))
	{
		*line = main_action(&buf[fd]);
		return (1);
	}
	if (res == 0 && ft_strlen(buf[fd]))
	{
		*line = buf[fd];
		buf[fd] = NULL;
		return (1);
	}
	return (-1);
}

static int	join_check(char **buf, char *tmp, int fd)
{
	if (!(buf[fd] = ft_strjoin(buf[fd], tmp)))
	{
		free(buf[fd]);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf[12000];
	int			res;
	char		tmp[BUFF_SIZE + 1];
	char		*tmp2;

	if (!line || BUFF_SIZE <= 0 || fd < 0
	|| fd > 12000 || (res = read(fd, tmp, 0)) < 0)
		return (-1);
	if (buf[fd] == NULL)
		buf[fd] = ft_strnew(1);
	while ((res = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[res] = '\0';
		tmp2 = buf[fd];
		if (join_check(buf, tmp, fd) == 1)
			return (-1);
		free(tmp2);
		if (ft_strchr(buf[fd], '\n'))
			break ;
	}
	if (check_lines(buf, line, fd, res) == 1)
		return (1);
	return (0);
}
