#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

class RPN {
	private:
		std::stack<int> stk;
		void calculate(std::string& token);
	public:
		// OCCF
		RPN();
		RPN(const RPN& a);
		RPN& operator=(const RPN& a);
		virtual ~RPN();
		// Member functions
		void doRPN(std::string& line);
};

#endif
