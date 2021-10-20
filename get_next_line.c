#include "get_next_line.h"



#include <stdio.h>

char *get_next_line_input(void)
{
	return (0);
}

char *get_next_line_fd(int fd)
{
	char *buf;
	int  i;
	char c;

	if (read(fd, &c, 1) != 1)
		return (0);
	i = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (0);
	buf[i++] = c;
	while (read(fd, &buf[i], 1) == 1)
	{
		if (buf[i] == '\n')
		{
			buf[++i] = '\0';
			if (ft_strlen(buf))
			{
				printf("%s", buf);
				return (buf);
			}
		}
		i++;
	}
	buf[i] = '\0';
	if (ft_strlen(buf))
		return (buf);
	printf("qwe");
	free(buf);
	return (0);
}

char *get_next_line(int fd)
{
	if (!fd)
		return (0);
	if (fd < 0)
		return (0);
	if (fd == 0)
		return (get_next_line_input());
	else
		return (get_next_line_fd(fd));
}
