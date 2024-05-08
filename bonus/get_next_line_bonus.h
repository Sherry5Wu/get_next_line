#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (42)
#endif

#include <limits.h>
#include <sys/types.h> // for sszie_t

char *get_next_line(int fd);

#endif
