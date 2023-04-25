NAME = phonebook
SRCS = phonebook.cpp contacts.cpp
INCL = phonebook.hpp ##contacts.hpp?
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

fclean :
	@make clean
	@rm -rf ${NAME}

.PHONY : all re clean fclean
