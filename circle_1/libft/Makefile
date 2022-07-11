# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 14:01:08 by hyeslim           #+#    #+#              #
#    Updated: 2022/07/11 14:01:56 by hyeslim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strncmp.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
BSRCS =  ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c
OBJS = ${SRCS:.c=.o}
BOBJS = ${BSRCS:.c=.o}

all : ${NAME}

bonus : ${NAME}
	${CC} -c ${CFLAGS} ${BSRCS} -I./
	ar rc ${NAME} ${BOBJS}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

${OBJS} : ${SRCS}
	${CC} -c ${CFLAGS} ${SRCS} -I./

clean :
	rm -f ${OBJS} ${BOBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re



# NAME = libft.a
# SRCS = ${DIR}ft_putchar.c ${DIR}ft_putstr.c ${DIR}ft_strcmp.c ${DIR}ft_strlen.c ${DIR}ft_swap.c
# OBJS = ${SRCS:.c=.o}
# CC = gcc
# CFLAGS = -Wall -Werror -Wextra
# DIR = ./srcs/
# INC = ./includes


# all : ${NAME}

# %.o : %.c
# 	${CC} ${CFLAGS} -c $^ -o $@ -I${INC}

# ${NAME} : ${OBJS}
# 	ar rc ${NAME} ${OBJS}

# clean :
# 	rm -f ${OBJS}

# fclean : clean
# 	rm -f ${NAME}

# re : fclean all
