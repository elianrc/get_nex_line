//To compile:
// gcc mainb.c -Wall -Wextra -Werror -D BUFFER_SIZE=32 ../get_next_line_bonus.c ../get_next_line_utils_bonus.c

//For Valgrind(Linux Mint):
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "../get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int fd1, fd2, fd3, rt;
    int lc = 1;
    char *line;

    if (argc == 4)
    {
        fd1 = open(argv[1], O_RDONLY);
        printf("____________FD 1_______________\n");
        while ((rt = get_next_line(fd1, &line)) > 0)
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
        close(fd1);

        //_______________________________________________

        fd2 = open(argv[2], O_RDONLY);
        printf("____________FD 2_______________\n");

        while ((rt = get_next_line(fd2, &line)) > 0)
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
        close(fd2);

        //_______________________________________________

        fd3 = open(argv[3], O_RDONLY);
        printf("____________FD 3_______________\n");
        while ((rt = get_next_line(fd3, &line)) > 0)
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
        close(fd3);
    }
    else
    {
        printf("[ USAGE ERROR ] Insufficient Command Line Arguments\n");
        return (1);
    }
}


