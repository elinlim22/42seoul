# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 19:07:47 by hyeslim           #+#    #+#              #
#    Updated: 2022/11/26 21:24:45 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
CC = CC
CFLAGS = -Wall -Werror -Wextra
SRCS = *.c
MLX	= -lmlx -framework Appkit -framework OpenGL

all : ${NAME}

${NAME} :
	@make bonus -C libft
	@mv libft/libft.a ./
	@${CC} ${CFLAGS} -c ${SRCS} -I so_long.h
#	 @make -C mlx
	@ar rcs ${NAME} *.o
	@make clean
	@${CC} ${CFLAGS} ${MLX} main.c so_long.a libft.a -o so_long
#	@mv mlx/libmlx.dylib ./

clean :
	@rm -rf *.o
	@rm -rf libft/*.o
#	@rm -rf mlx/*.o

fclean : clean
	@rm -rf ${NAME}
#	@rm libmlx.dylib
	@rm so_long
	@rm libft.a

re :
	@make fclean
	@make all
	@make clean

.PHONY : all clean fclean re
