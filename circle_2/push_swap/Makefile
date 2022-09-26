# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 14:17:26 by hyeslim           #+#    #+#              #
#    Updated: 2022/09/26 14:20:09 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = *.c #fixxxxx

all : ${NAME}

${NAME} :
	${CC} ${CFLAGS} -c libft/*.c -I libft/libft.h
	${CC} ${CFLAGS} -c ${SRCS} -I push_swap.h
	ar rcs ${NAME} *.o

clean :
	rm -rf *.o libft/*.o

fclean : clean
	rm -rf ${NAME}

re :
	make fclean
	make all

.PHONY : all clean fclean re
