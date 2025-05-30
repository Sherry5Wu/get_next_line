SRCS := get_next_line.c get_next_line_utils.c main_get_next_line.c

CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := get_next_line

all: ${NAME}

${NAME}: ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
