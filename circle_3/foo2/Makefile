# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 12:38:33 by hyeslim           #+#    #+#              #
#    Updated: 2023/03/07 12:47:39 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
TFLAGS = -g3 -fsanitize=thread
SRCS = ${addsuffix .c, ${FILE}}
FILE = init_bonus main_bonus philo_bonus utils_bonus
INCL = -I ./philo_bonus.h

all : ${NAME}

${NAME} : ${SRCS}
	${CC} ${CFLAGS} ${TFLAGS} ${SRCS} ${INCL} -o ${NAME}

re :
	@make fclean
	@make all
	@make clean

clean :
	@rm -rf *.o

fclean :
	@make clean
	@rm -rf ${NAME}

.PHONY : all re clean fclean
