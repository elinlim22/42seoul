NAME = Sed
SRCS = ${addsuffix .cpp, main}
INCL = ${addsuffix .hpp, Sed}
CPP = c++ -Wall -Werror -Wextra -std=c++98
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@${CPP} ${OBJS} -o ${NAME}

%.o: %.cpp #-I ${INCL}
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
