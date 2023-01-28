# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 01:36:38 by hyeslim           #+#    #+#              #
#    Updated: 2023/01/28 19:38:28 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra
TFLAGS = -g3 -fsanitize=address ###

FILE = main_bonus
SRCS = ${addsuffix .c, ${FILE}}

all : ${NAME}

${NAME} : ###
	@${CC} ${CFLAGS} ${TFLAGS} ${SRCS} -o ${NAME}

re :
	@make fclean
	@make all
	@make clean

clean : ###
	@rm -rf

fclean :
	@make clean
	@rm -rf ${NAME}

.PHONY : all re clean fclean
