#include "get_next_line_bonus.h"

static char *get_buffer(int fd, char *buffer)
{
    char *tmp_buffer;
    int read_bytes;

    tmp_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!tmp_buffer)
        return (NULL);
    while (!ft_strchr(buffer, '\n') && read_bytes > 0)
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(tmp_buffer);
            free(buffer);
            return (NULL);
        }
        tmp_buffer[read_bytes] = '\0';
        buffer = ft_strjoin(buffer, tmp_buffer, BUFFER_SIZE);
    }
    free(tmp_buffer);
    return (buffer);
}

static char *get_the_line(char *buffer)
{
    ssize_t size;
    char *line;

    size = 0;
    while (buffer[size] && buffer[size] != '\n')
        size++;
    line = (char *)malloc(sizeof(char) * (size + 2));
    if (!line)
        return (NULL);
    if (buffer[size] == '\n')
        buffer[size + 1] != '\0';
    while (size >= 0)
    {
        line[size] = buffer[size];
        size--;
    }
    return (line);
}

static char *get_rest(char *buffer)
{
    // 还没有写完
}

char *get_next_line(int fd)
{
    char *line;
    static char *buffer[OPEN_MAX];

    if (line == NULL)
    {
        line = (char *)malloc(sizeof(char));
        *line = '\0';
    }
    if (buffer == NULL)
    {
        buffer = (char **)malloc(sizeof(char *));
        *buffer = "\0";
    }
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer[fd] = get_buffer(fd, buffer[fd]);
    if (!buffer[fd])
        return (NULL);
    line = get_the_line(buffer[fd]);
    if (!line)
        return (NULL);
    buffer[fd] = get_rest(buffer[fd]);
    return (line);
}