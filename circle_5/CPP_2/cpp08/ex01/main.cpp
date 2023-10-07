#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		std::cerr << "Usuage: $>./Span {range} {count}" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	Span sp = Span(100000);
	sp.addNumber(1);
	sp.addNumber(4);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(5);
	std::cout << "sp value >>> ";
	sp.printValue();
	std::cout << std::endl;

	Span sp2 = Span(5);
	sp2 = sp; // -> sp2 now have max size 1000 and sp value
	std::cout << "sp2 value >>> ";
	sp.printValue();
	std::cout << std::endl;

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
	sp.addNumbers(v.begin(), v.end());

	// std::cout << "sp value now >>> ";
	// sp.printValue();
	// std::cout << std::endl;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

// Test case : $>./Span 1000000000 99995
