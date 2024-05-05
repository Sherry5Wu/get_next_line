
/*
Using linkedlist type to store fd and content.
typedef struct s_list
{
    int     fd;
    char    *content;
    struct s_list *next;
}   t_list;

*/
char *get_next_line(int fd)
{
    char *line;
    static char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = get_buffer(fd, buffer);
    line = get_the_line(buffer);
    buffer = get_rest(buffer);
    return (line);
}