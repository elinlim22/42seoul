NAME = ClapTrap
SRCS = ${addsuffix .cpp, main ClapTrap}
INCL = ${addsuffix .hpp, ClapTrap}
CPP = c++ -Wall -Werror -Wextra -std=c++98
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@${CPP} ${OBJS} -o ${NAME}

%.o: %.cpp
	@${CPP} -c $< -o $@ -I ${INCL}

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
