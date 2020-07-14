//To compile:
// gcc main.c -Wall -Wextra -Werror -D BUFFER_SIZE=32 ../get_next_line.c ../get_next_line_utils.c

//for Valgrind(Linux Mint):
// valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out


#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "../get_next_line.h"



int main(int argc, char **argv)
{
    int fd, rt;
    int lc = 1;
    char *line;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while ((rt = get_next_line(fd, &line)) > 0)
        {
            printf("[ Return Value: %d ] #%d Line read: %s\n", rt, lc, line);
            lc++;
            free(line);
        }
        printf("[ Return Value: %d ] #%d Line read: %s\n", rt, lc++, line);
        if (rt == -1)
        {
            printf("[ ERROR ]\n");
            return (1);
        }
        else if (rt == 0)
        {
            printf("[ EOF reached ]\n");
            free(line);
        }
        close(fd);
    }
    else if (argc == 1)
    {
        printf("Enter text: \n");
        while ((rt = get_next_line(0, &line)) > 0)
        {
            printf("[ Return Value: %d ] Line read: %s\n", rt, line);
        }
        if (rt == -1)
        {
            printf("[ ERROR ]\n");
            return (1);
        }
        else if (rt == 0)
        {
            printf("[ EOF reached ]\n");
        }
    }
    
}