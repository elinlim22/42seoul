#ifndef SPAN_HPP
#define SPAN_HPP

class Span {
	private:
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
