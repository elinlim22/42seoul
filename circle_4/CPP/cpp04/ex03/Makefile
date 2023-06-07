NAME = AMateria
SRCS = ${addsuffix .cpp, main AMateria Ice Cure Character MateriaSource}
INCL = ${addsuffix .hpp, AMateria Ice Cure Character ICharacter MateriaSource IMateriaSource}
CC = c++ -Wall -Werror -Wextra -std=c++98 # -fsanitize=address -g3
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS} ${INCL}
	@${CC} ${OBJS} -o ${NAME}

%.o: %.cpp #${INCL}
	@${CC} -c $< -o $@

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
