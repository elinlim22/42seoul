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
		this->stk = a.stk;
	} return *this;
}

RPN::~RPN() {}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void RPN::doRPN(std::string& line) {
	std::istringstream iss(line);
	std::string input;

	try {
		while (iss >> input) {
			int check = std::atoi(input.c_str());
			if (input[0] == '0' || (input[0] != '0' && check != 0)) {
				if (10 <= check) throw std::exception();
				stk.push(check);
			} else {
				if (stk.size() < 2) throw std::exception();
				calculate(input);
			}
		}
		if (stk.size() == 1)
			std::cout << stk.top() << std::endl;
		else throw std::exception();
	} catch (std::exception&) {
		std::cerr << "Error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void RPN::calculate(std::string& token) {
	int operand1;
	int operand2;

	if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
		operand2 = stk.top();
		stk.pop();
		operand1 = stk.top();
		stk.pop();

		switch (token[0]) {
			case '+':
				operand1 = operand1 + operand2;
				break ;
			case '-':
				operand1 = operand1 - operand2;
				break ;
			case '*':
				operand1 = operand1 * operand2;
				break ;
			case '/':
				if (operand2 == 0) throw std::exception();
				operand1 = operand1 / operand2;
				break ;
		}
		stk.push(operand1);
	} else throw std::exception();
}
