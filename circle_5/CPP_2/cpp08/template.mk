CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJS} ${INCL}
	@${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
	@${CXX} ${CXXFLAGS} -c $< -o $@

re :
	@make fclean
	@make all

clean :
	@rm -rf *.o
	@rm -rf *.replace

fclean :
	@make clean
	@rm -rf ${NAME}

.PHONY : all re clean fclean
