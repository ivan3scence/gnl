#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd);

int main()
{
	char *s;
	int fd;
	int i=9;
	fd = open("1.txt", O_RDONLY);
	while (i--)
	{
		s = get_next_line(fd);
		printf("%s\n", s);
		free(s);
	}
}
