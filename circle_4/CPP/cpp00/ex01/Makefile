NAME = ??
SRCS = ??.cpp
CPP = c++ -Wall -Werror -Wextra -std=c++98
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CPP} ${OBJS} -o ${NAME}

%.o: %.cpp
	${CPP} -c $< -o $@

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
