#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <ctime>

#define NOT_ENOUGH_NUMBERS 1
#define FULL_NUMBERS 2

class Span {
	private:
		std::vector<int> numbers;
		unsigned int max;
		Span();
	public:
		Span(unsigned int max);
		Span(const Span& a);
		Span& operator= (const Span& a);
		virtual ~Span();

		void addNumber(int n);
		void addNumbers(unsigned int range);
		int shortestSpan() const;
		int longestSpan() const;
		void printError(int flag) const;
};

#endif
