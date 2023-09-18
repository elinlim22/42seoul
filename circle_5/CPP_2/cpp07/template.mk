CPP = c++ -Wall -Werror -Wextra -std=c++98 -pedantic-errors ## pedantic check
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS} ${INCL}
	@${CPP} ${OBJS} -o ${NAME}

%.o: %.cpp
	@${CPP} -c $< -o $@

re :
	@make fclean
	@make all
	@make clean

clean :
	@rm -rf *.o
	@rm -rf *.replace

fclean :
	@make clean
	@rm -rf ${NAME}

.PHONY : all re clean fclean
