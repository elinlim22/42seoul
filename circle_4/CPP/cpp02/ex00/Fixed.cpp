#include "Fixed.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Fixed::Fixed() : num(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed& a) {
	std::cout << "Copy constructor called" << std::endl;
	this->num = a.getRawBits();
}

Fixed& Fixed::operator= (const Fixed& a) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = a.getRawBits();
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/* -------------------------------------------------------------------------- */
/*                              Member Functions                              */
/* -------------------------------------------------------------------------- */
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return num;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	num = raw;
}
