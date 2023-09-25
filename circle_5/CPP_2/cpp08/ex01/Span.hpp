#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
	private:
		std::vector<int> v;
		unsigned int amount;
		unsigned int* arr;
		Span();
	public:
		Span(unsigned int max);
		Span(const Span& a);
		Span& operator= (const Span& a);
		virtual ~Span();
		void addNumber(int n); // -> if amount == max, throw std::exception
		int shortestSpan() const;
		int longestSpan() const;

};

#endif
