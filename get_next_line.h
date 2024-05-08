#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE (42)
#endif

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
char *ft_strchr(const char *str, int c);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlen(const char *str);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlcat(char *dest, const char *src, size_t size);
char *ft_strdup(const char *str);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif