NAME = Brain
SRCS = ${addsuffix .cpp, main Brain AbstAnimal Dog Cat}
INCL = ${addsuffix .hpp, Brain AbstAnimal Dog Cat}
CPP = c++ -Wall -Werror -Wextra -std=c++98
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${INCL} ${OBJS}
	@${CPP} ${OBJS} -o ${NAME}

%.o: %.cpp ${INCL}
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
