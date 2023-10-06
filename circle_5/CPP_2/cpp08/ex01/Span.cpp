#include "Span.hpp"

/* -------------------------------------------------------------------------- */
/*                                    OCCF                                    */
/* -------------------------------------------------------------------------- */
Span::Span() {}

Span::Span(unsigned int _max) {
	this->max = _max;
}

Span::Span(const Span& a) {
	*this = a;
}

Span& Span::operator= (const Span& a) {
	if (this != &a) {
		this->max = a.max;
		this->numbers.assign(a.numbers.begin(), a.numbers.end());
	}
	return *this;
}

Span::~Span() {

}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void Span::addNumber(int n) {
	if (this->numbers.size() == this->max) printError(FULL_NUMBERS);
	numbers.push_back(n);
}

int Span::shortestSpan() const {
	if (numbers.size() <= 1) printError(NOT_ENOUGH_NUMBERS);
	std::vector<int> sortedNumbers;
	sortedNumbers.assign(numbers.begin(), numbers.end());
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 2; i < sortedNumbers.size(); i++) {
		if (sortedNumbers[i] - sortedNumbers[i - 1] < shortSpan)
			shortSpan = sortedNumbers[i] - sortedNumbers[i - 1];
	}
	return shortSpan;
}

int Span::longestSpan() const {
	if (numbers.size() <= 1) printError(NOT_ENOUGH_NUMBERS);
	std::vector<int> sortedNumbers;
	sortedNumbers.assign(numbers.begin(), numbers.end());
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int longSpan = sortedNumbers.back() - sortedNumbers.front();
	return longSpan;
}

void Span::printError(int flag) const {
	try {
		switch (flag) {
			case NOT_ENOUGH_NUMBERS:
				throw std::runtime_error("The vector has only one number");
			case FULL_NUMBERS:
				throw std::runtime_error("The vector is full");
		}
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
