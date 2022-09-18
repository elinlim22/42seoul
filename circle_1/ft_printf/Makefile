# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 15:44:49 by hyeslim           #+#    #+#              #
#    Updated: 2022/09/18 17:15:50 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c utils.c

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -c libft/*.c -I libft/libft.h
	${CC} ${CFLAGS} -c ${SRCS} -I ft_printf.h
	ar rcs ${NAME} *.o

clean :
	rm -rf *.o libft/*.o

fclean : clean
	rm -rf ${NAME}

re :
	make fclean
	make all

.PHONY : all clean fclean re
