# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 19:07:47 by hyeslim           #+#    #+#              #
#    Updated: 2022/11/22 17:33:13 by hyeslim          ###   ########.fr        #
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
	make -C minilibx_mms
	ar rcs ${NAME} *.o
	${CC} ${CFLAGS} -Lminilibx_mms -lmlx -framework Cocoa \
		-framework Metal -framework Metalkit -framework Quartzcore main.c so_long.a -o so_long
	mv minilibx_mms/libmlx.dylib ./
	make clean

clean :
	rm *.o libft/*.o minilibx_mms/*.o libmlx.dylib

fclean : clean
	rm -rf ${NAME}
	rm so_long

re :
	make fclean
	make all
	make clean

.PHONY : all clean fclean re
