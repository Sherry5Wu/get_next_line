SRCS   := ${wildcard *.c}
#HEADER   = get_next_line.h
HEADER  = get_next_line_bonus.h

AR     = ar rc
RM     = rm -f
LIB    = ranlib
CC     = cc
CFLAGS = -Wall -Wextra -Werror

NAME = test

all: ${NAME}

${NAME}: ${HEADER} ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -I $< -o $@

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re:	fclean all

.PHONY:		all fclean re