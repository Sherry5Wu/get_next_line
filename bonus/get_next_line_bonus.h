
#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (42)
#endif

#include <limits.h> // for OPEN_MAX
#include <sys/types.h> // for sszie_t
#include <stdlib.h> // for malloc

char *get_next_line(int fd);
size_t  slen(char  *str);
char    *ft_strjoin(char *dest, char *src);
char    *ft_strchr(const char *str, int c);
void     *free_mem(char  **str);
char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif
