#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed const b(Fixed(30.5f) * Fixed(2.0f));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

/*
Should return :
	$> ./a.out
	0
	0.00390625
	0.00390625
	0.00390625
	0.0078125
	10.1016
	10.1016
	$>
*/
