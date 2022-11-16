# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 19:07:47 by hyeslim           #+#    #+#              #
#    Updated: 2022/11/16 19:31:35 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
CC = CC
CFLAGS = -Wall -Werror -Wextra
SRCS = *.c

all : ${NAME}

${NAME} :
	${CC} ${CFLAGS} -c libft/*.c -I libft/libft.h
	${CC} ${CFLAGS} -c ${SRCS} -I so_long.h
	ar rcs ${NAME} *.o
	make clean
#	${CC} ${CFLAGS} main.c so_long.a -o so_long
	${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL \
		-framework Appkit main.c so_long.a -o so_long

clean :
	rm -rf *.o libft/*.o

fclean : clean
	rm -rf ${NAME}
	rm so_long

re :
	make fclean
	make all
	make clean

.PHONY : all clean fclean re
