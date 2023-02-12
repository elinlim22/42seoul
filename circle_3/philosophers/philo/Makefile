# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 01:21:19 by hyeslim           #+#    #+#              #
#    Updated: 2023/02/12 18:02:17 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra
TFLAGS = -g3 -fsanitize=thread ###

FILE = main init philo utils works
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
