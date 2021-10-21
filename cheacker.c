#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd);

int main()
{
	char *s;
	int fd;
	//int i=9;
	fd = open("simple", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
	free(s);


	//s = malloc(0);
	//printf("%s\n%p\n",s, s);
	//printf("%d\n", s[0]);
	//printf("%d\n", s[1]);


	// while (1)
	// 	;

	//int i=6;
	//char c;
	//int fd=open("1.txt", O_RDONLY);
	//while (i--)
	//	printf("%zd, %d\n", read(fd, &c, 1), c);
}


//int main()
//{
//	char *s;
//
//	s = get_next_line(0);
//	printf("%s", s);
//}
