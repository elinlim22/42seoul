#include "Span.hpp"

int main()
{
	Span sp = Span(100);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	sp.addNumbers(100);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

/* Should print
$> ./ex01
2
14
$>
*/
