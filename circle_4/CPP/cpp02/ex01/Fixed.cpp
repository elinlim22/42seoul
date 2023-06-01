#include "Fixed.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Constructors                               */
/* -------------------------------------------------------------------------- */
Fixed::Fixed() : num(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed& a) {
	std::cout << "Copy constructor called" << std::endl;
	// num = a.getRawBits();
	*this = a;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	num = i * (1 << bit);
}
Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	num = roundf(f * (1 << bit));
}

Fixed& Fixed::operator= (const Fixed& a) {
	std::cout << "Copy assignment operator called" << std::endl;
	num = a.getRawBits();
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

float Fixed::toFloat(void) const {
	return (static_cast<float>(num) / static_cast<float>((1 << bit)));
}
int Fixed::toInt(void) const {
	return (num / (1 << bit));
}

/* -------------------------------------------------------------------------- */
/*                              Global Functions                              */
/* -------------------------------------------------------------------------- */
std::ostream& operator<< (std::ostream& out, const Fixed& a) {
	out << a.toFloat();
	return out;
}
