#include "RPN.hpp"

/* -------------------------------------------------------------------------- */
/*                                    OCCF                                    */
/* -------------------------------------------------------------------------- */
RPN::RPN() {}

RPN::RPN(const RPN& a) {
	*this = a;
}

RPN& RPN::operator= (const RPN& a) {
	if (this != &a) {

	} return *this;
}

RPN::~RPN() {}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void RPN::calculate(std::string& line) {
	std::istringstream iss(line);
	int input;
	char c;
	while (iss.eof()) {
		// if (iss >> input) {
		// 	std::cout << input << std::endl;
		// 	// (void)iss;
		// } else if (iss >> c) {
		// 	std::cout << c << std::endl;
		// 	// (void)iss;
		// }

	}
}
