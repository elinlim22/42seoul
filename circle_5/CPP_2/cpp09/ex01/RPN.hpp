#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN {
	private:
		std::stack<int> stk;
	public:
		// OCCF
		RPN();
		RPN(const RPN& a);
		RPN& operator=(const RPN& a);
		virtual ~RPN();
		// Member functions
		void calculate(std::string& line);
};

#endif
