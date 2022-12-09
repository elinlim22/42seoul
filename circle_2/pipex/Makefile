# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 00:42:27 by hyeslim           #+#    #+#              #
#    Updated: 2022/12/09 22:30:21 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
SRCS = *.c
INCL = *.h

all : ${NAME}

${NAME} :
	@make bonus -C libft
	@make clean -C libft
	@mv libft/libft.a ./
	@${CC} ${CFLAGS} -c ${SRCS} -I ${INCL}
	@ar rcs pipex.a *.o
	@${CC} ${CFLAGS} main.c libft.a pipex.a -o ${NAME}

clean :
	@rm -rf *.o
	@rm -rf libft/*.o

fclean : clean
	@rm -rf libft.a pipex.a
	@rm -rf ${NAME}

re :
	@make fclean
	@make all
	@make clean

.PHONY : all clean fclean re
