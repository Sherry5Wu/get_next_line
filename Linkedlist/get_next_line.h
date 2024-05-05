#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE (42)

typedef struct s_list
{
    char *data;
    struct s_list *next;
} t_list;

char *get_next_line(int fd);
void read_content(int fd, t_list *list_header);

t_list *ft_lstnew(void *content);
void ft_lstadd_back(t_list **lst, t_list *new);

char *ft_strchr(const char *str, int c);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlen(const char *str);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlcat(char *dest, const char *src, size_t size);
char *ft_strdup(const char *str);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif