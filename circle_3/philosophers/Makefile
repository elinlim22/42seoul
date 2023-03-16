# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 01:21:19 by hyeslim           #+#    #+#              #
#    Updated: 2023/03/16 23:14:42 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra

FILE = main init philo utils
SRCS = ${addsuffix .c, ${FILE}}

all : ${NAME}

${NAME} :
	@${CC} ${CFLAGS} ${SRCS} -I philo.h -o ${NAME}

re :
	@make fclean
	@make all
	@make clean

clean :
	@rm -rf *.o

fclean :
	@rm -rf ${NAME}

.PHONY : all re clean fclean
