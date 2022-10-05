# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 14:17:26 by hyeslim           #+#    #+#              #
#    Updated: 2022/10/05 22:11:56 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = *.c #fixxxxx
#rm a.out 삭제해야함

all : ${NAME}

${NAME} :
	${CC} ${CFLAGS} -c libft/*.c -I libft/libft.h
	${CC} ${CFLAGS} -c ${SRCS} -I push_swap.h
	ar rcs ${NAME} *.o

clean :
	rm -rf *.o libft/*.o

fclean : clean
	rm -rf ${NAME}
	rm a.out

re :
	make fclean
	make all
	rm a.out

.PHONY : all clean fclean re
