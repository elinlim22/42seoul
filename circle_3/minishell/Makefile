# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 18:32:09 by hyeslim           #+#    #+#              #
#    Updated: 2022/12/27 20:49:12 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS = minishell.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -lreadline ##

all : ${NAME}
	@make bonus -C libft
	@make clean -C libft
	@mv libft/libft.a ./
	@${CC} ${CFLAGS} ${SRCS} -I minishell.h
# @ar rcs minishell.a ${OBJS}
	@${CC} ${CFLAGS} minishell.c libft.a minishell.a -o ${NAME}
	@make clean
# @${CC} ${CFLAGS} -c libft/*.c ${SRCS}
# @ar rcs minishell.a *.o
# @${CC} ${CFLAGS} minishell.a -o ${NAME}
# @make clean

re :
	@make fclean
	@make all
	@make clean

clean :
	@rm -rf ${OBJS}

fclean :
	@make clean
	@rm -rf libft.a
	@rm -rf minishell.a

.PHONY : all re clean fclean
