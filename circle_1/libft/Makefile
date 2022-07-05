NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS := $(wildcard *.c)
OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

${OBJS} : ${SRCS}
	${CC} -c ${CFLAGS} ${SRCS}


