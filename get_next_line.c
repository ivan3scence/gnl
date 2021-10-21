/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:58:08 by sdonny            #+#    #+#             */
/*   Updated: 2021/10/21 17:58:18 by sdonny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_rebuf(char *buf, int i)
{
	int		n;
	char	*new_buf;

	n = -1;
	new_buf = (char *)malloc(sizeof(char) * (i + BUFFER_SIZE));
	if (!new_buf)
		return (0);
	while (++n < i)
		new_buf[n] = buf[n];
	free(buf);
	buf = new_buf;
	return (buf);
}

char	*get_next_line_fd(int fd, int ii, int i)
{
	static char	*buf;

	buf = (char *)malloc(sizeof(char) * ii);
	if (!buf)
		return (0);
	while (read(fd, &buf[i], 1) == 1)
	{
		if (i + 1 >= ii)
		{
			buf = ft_rebuf(buf, ii);
			ii += BUFFER_SIZE;
			if (!buf)
				return (0);
		}
		if (buf[i++] == '\n')
			break ;
	}
	if (!i)
	{
		free(buf);
		return (0);
	}
	buf[i] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	int	buf_size;
	int	i;

	i = 0;
	buf_size = BUFFER_SIZE;
	if (BUFFER_SIZE <= 0)
		return (0);
	if (fd < 0)
		return (0);
	else
		return (get_next_line_fd(fd, buf_size, i));
}
