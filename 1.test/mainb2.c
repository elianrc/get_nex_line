//To compile:
//gcc mainb2.c -Wall -Wextra -Werror -D BUFFER_SIZE=32 ../get_next_line_bonus.c ../get_next_line_utils_bonus.c

//For Valgrind(linux mint):
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "../get_next_line_bonus.h"

int main(void)
{
	int fd01, fd02, fd03;
	char *line = NULL;
	fd01 = open("bfile1", O_RDONLY);
	fd02 = open("bfile2", O_RDONLY);
	fd03 = open("bfile3", O_RDONLY);
	//FD 01
	printf("FD01 | First Line | FD return %d\n", get_next_line(fd01, &line));
	printf("%s\n\n", line);
	free(line);
	//FD02
	printf("FD02 | First Line | FD return %d\n", get_next_line(fd02, &line));
	printf("%s\n\n", line);
	free(line);
	//FD03
	printf("FD03 | First Line | FD return %d\n", get_next_line(fd03, &line));
	printf("%s\n\n", line);
	free(line);
	//FD01 Seconda Line
	printf("FD01 | Second Line | FD return %d\n", get_next_line(fd01, &line));
	printf("%s\n\n", line);
	free(line);
	//FD03 Second Line
	printf("FD03 | Second Line | FD return %d\n", get_next_line(fd03, &line));
	printf("%s\n\n", line);
	free(line);
	printf("FD03 | Third Line | FD return %d\n", get_next_line(fd03, &line));
	printf("%s\n\n", line);
	free(line);
}