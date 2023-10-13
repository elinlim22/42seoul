#include "RPN.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) return (static_cast<void>(std::cerr << "Error: Wrong input" << std::endl), -1);
	RPN rpn;
	std::string line = std::string(argv[1]);
	rpn.doRPN(line);
	return 0;
}
