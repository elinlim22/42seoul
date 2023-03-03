# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 01:21:19 by hyeslim           #+#    #+#              #
#    Updated: 2023/03/02 18:25:35 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra
TFLAGS = -g3 -fsanitize=thread ###

FILE = main init philo utils
SRCS = ${addsuffix .c, ${FILE}}

all : ${NAME}

${NAME} : ###
	@${CC} ${CFLAGS} ${SRCS} -o ${NAME}

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
