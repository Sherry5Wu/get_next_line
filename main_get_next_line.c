#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    // int fd_1;
    // int fd_e;
    int fd_2;
    char *line;
    int i;

    // fd_1 = open("tests/test1.txt", O_RDONLY);
    // fd_e = open("test/empty.txt", O_RDONLY);
    fd_2 = open("tests/test2.txt", O_RDONLY);
    for (i = 0; i < 4; i++)
    {
        // line = get_next_line(fd_1);
        // printf("From test1.txt\n");
        // printf("line[%02d]=%s", i, line); // output format is "01, 02,...10"
        // free(line);

        // line = get_next_line(fd_e);
        // printf("From empty.txt\n");
        // printf("line[%02d]=%s", i, line);
        // free(line);

        line = get_next_line(fd_2);
        printf("From test2.txt\n");
        printf("line[%02d]=%s", i, line);
        free(line);


    }
    // close(fd_1);
    // close(fd_e);
    close(fd_2);

    return (0);
}