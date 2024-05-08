#include "get_next_line.h"

/*
    Description:
    Write a function that returns a line read from a file descriptor.

    Parameters:
    fd: The file descriptor to read from.

    Return value:
    Read line: correct behavior.
    NULL: there is nothing else to read, or an error occurred.
*/
#include <stdio.h>
#include <unistd.h>
static char *get_buffer(int fd, char *buffer)
{
    ssize_t read_bytes;
    char *tmp_buffer;

    tmp_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!tmp_buffer)
        return (NULL);
    read_bytes = 1;
    while (!ft_strchr(buffer, '\n') && read_bytes > 0)
    {
        read_bytes = read(fd, tmp_buffer, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(tmp_buffer);
            free(buffer);
            return (NULL);
        }
        tmp_buffer[read_bytes] = '\0';
        buffer = ft_strjoin(buffer, tmp_buffer);
    }
    free(tmp_buffer);
//    printf("return_buffer=%s\n",buffer);
    return (buffer);
}

static char *get_the_line(char *buffer)
{
    char *line;
    int i;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 2));
    if (!line)
        return (NULL);

    if (buffer[i] == '\n')
        line[i + 1] = '\0';
    while (i >= 0)
    {
        line[i] = buffer[i];
        i--;
    }
//    printf("%s  line=%s", __FUNCTION__, line);
    return (line);
}

static char *get_rest(char *buffer)
{
    char *rest;
    int i;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    i++;
    rest = ft_substr(buffer, i, (ft_strlen(buffer) - i));
    free(buffer);
    return (rest);
}

char *get_next_line(int fd)
{
    char *line;
    static char *buffer;

    if (!buffer)
    {
        buffer = malloc(sizeof(char));
        *buffer = '\0';
    }
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = get_buffer(fd, buffer);
    if (!buffer)
        return (NULL);
    line = get_the_line(buffer);
    buffer = get_rest(buffer);
    return (line);
}