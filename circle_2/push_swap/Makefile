# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 14:17:26 by hyeslim           #+#    #+#              #
#    Updated: 2022/11/14 13:55:34 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = check.c commands.c init.c main.c push_pop.c push_swap.c sort_5.c

all : ${NAME}

${NAME} :
	${CC} ${CFLAGS} -c libft/*.c -I libft/libft.h
	${CC} ${CFLAGS} -c ${SRCS} -I push_swap.h
	ar rcs ${NAME} *.o
	make clean
	${CC} ${CFLAGS} main.c push_swap.a

clean :
	rm -rf *.o libft/*.o

fclean : clean
	rm -rf ${NAME}
	rm a.out

re :
	make fclean
	make all
	make clean

.PHONY : all clean fclean re
