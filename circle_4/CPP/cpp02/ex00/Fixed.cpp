#include "Fixed.hpp"

/*
class Fixed {
	private:
		int num; //store the fixed-point number value
		static const int bit; //store the number of fractional bits. always be the integer literal 8.
	public:
		Fixed();
		Fixed(const Fixed &a);
		Fixed &operator= (const Fixed &a);
		~Fixed();
		int getRawBits(void) const; //returns the raw value of the fixed-point value
		void setRawBits(int const raw); //sets the raw value of the fixed-point number
};
*/

Fixed::Fixed() : num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a) {
	std::cout << "Copy constructor called" << std::endl;
	this->num = a.getRawBits();
}

Fixed& Fixed::operator= (const Fixed &a) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = a.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return num;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	num = raw;
}
