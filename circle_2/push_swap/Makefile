# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 14:17:26 by hyeslim           #+#    #+#              #
#    Updated: 2022/11/03 16:39:29 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = commands_tester.c commands.c init.c foo.c #fixxxxx
#rm a.out 삭제해야함
#line 26 삭제

all : ${NAME}

${NAME} :
	${CC} ${CFLAGS} -c libft/*.c -I libft/libft.h
	${CC} ${CFLAGS} -c ${SRCS} -I push_swap.h
	ar rcs ${NAME} *.o
#	gcc ${CFLAGS} push_swap.c push_swap.a
#	gcc ${CFLAGS} foo.c push_swap.a
	make clean

clean :
	rm -rf *.o libft/*.o

fclean : clean
	rm -rf ${NAME}
#	rm a.out

re :
	make fclean
	make all
	make clean

.PHONY : all clean fclean re
