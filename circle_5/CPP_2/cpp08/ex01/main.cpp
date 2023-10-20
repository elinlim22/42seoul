#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		std::cerr << "Usuage: $>./Span {range} {count}" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	// // Subject main test
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	// return 0;

	// Making a random sequence of numbers
	std::vector<int> v;
	std::srand(static_cast<unsigned int>(std::time(0)));
	unsigned int range = std::atoi(argv[1]);
	unsigned int count = std::atoi(argv[2]);
	for (unsigned int i = 0; i < count; i++) {
		if (!range) {
			std::cerr << "Error: Random number with range of 0 cannot be generated" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		int rd = std::rand() % range + 1;
		v.push_back(rd);
	}

	Span sp = Span(count);
	sp.addNumbers(v.begin(), v.end());

	std::cout << "sp value now >>> ";
	sp.printValue();
	std::cout << std::endl;

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	return 0;
}
