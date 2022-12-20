# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 18:32:09 by hyeslim           #+#    #+#              #
#    Updated: 2022/12/20 18:41:03 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS =
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address ##

all : ${NAME}
	@make bonus -C libft
	@make clean -C libft
	@mv libft/libft.a ./
	@${CC} ${CFLAGS} -c ${SRCS} -I minishell.h
	@ar rcs minishell.a ${OBJS}
	@${CC} ${CFLAGS} minishell.c libft.a minishell.a -o ${NAME}
	@make clean

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
