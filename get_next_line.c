#include "get_next_line.h"

char *get_next_line_input(void)
{
	return (0);
}

char *get_next_line_fd(int fd)
{
	char *buf;
	int  i;

	i = -1;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (0);
	while (read(fd, &buf[++i], 1) != -1)
	{
		if (buf[i] == '\n' || buf[i] == -1)
		{
			buf[i] = '\0';
			return (buf);
		}
	}
	buf[i] = '\0';
	return (buf);
}

char *get_next_line(int fd)
{
	if (fd < 0)
		return (0);
	if (fd == 0)
		return (get_next_line_input());
	else
		return (get_next_line_fd(fd));
}
