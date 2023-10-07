#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

#define NOT_ENOUGH_NUMBERS 1
#define FULL_NUMBERS 2

class Span {
	private:
		std::vector<int> numbers;
		unsigned int max;
		Span();
		void printError(int flag) const;
	public:
		// OCCF
		Span(unsigned int max);
		Span(const Span& a);
		Span& operator= (const Span& a);
		virtual ~Span();

		// Member functions
		void addNumber(int n);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan() const;
		int longestSpan() const;
		void printValue() const;
};

#endif
