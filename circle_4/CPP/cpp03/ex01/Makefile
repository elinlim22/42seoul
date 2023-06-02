NAME = ScavTrap
SRCS = ${addsuffix .cpp, main ClapTrap ScavTrap}
INCL = ${addsuffix .hpp, ScavTrap}
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
