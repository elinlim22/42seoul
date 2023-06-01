#include "Fixed.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Constructors                               */
/* -------------------------------------------------------------------------- */
Fixed::Fixed() : num(0) {}

Fixed::Fixed(const Fixed& a) {
	// num = a.getRawBits();
	*this = a;
}

Fixed::Fixed(const int i) {
	num = i * (1 << bit);
}
Fixed::Fixed(const float f) {
	num = roundf(f * (1 << bit));
}

Fixed& Fixed::operator= (const Fixed& a) {
	num = a.getRawBits();
	return *this;
}
/* -------------------------------------------------------------------------- */
/*                              Operator overload                             */
/* -------------------------------------------------------------------------- */
// 6 comparison operators
bool Fixed::operator> (const Fixed& a) {
	return (this->toFloat() > a.toFloat());
}

bool Fixed::operator< (const Fixed& a) {
	return (this->toFloat() < a.toFloat());
}

bool Fixed::operator>= (const Fixed& a) {
	return (this->toFloat() >= a.toFloat());
}

bool Fixed::operator<= (const Fixed& a) {
	return (this->toFloat() <= a.toFloat());
}

bool Fixed::operator== (const Fixed& a) {
	return (this->toFloat() == a.toFloat());
}

bool Fixed::operator!= (const Fixed& a) {
	return (this->toFloat() != a.toFloat());
}

// 4 arithmetic operators
Fixed Fixed::operator+ (const Fixed& a) {
	return (Fixed(this->toFloat() + a.toFloat()));
}

Fixed Fixed::operator- (const Fixed& a) {
	return (Fixed(this->toFloat() - a.toFloat()));
}

Fixed Fixed::operator* (const Fixed& a) {
	return (Fixed(this->toFloat() * a.toFloat()));
}

Fixed Fixed::operator/ (const Fixed& a) {
	return (Fixed(this->toFloat() / a.toFloat()));
}

// 4 increment/decrement operators
Fixed& Fixed::operator++ (void) {
	this->num++;
	return *this;
}

const Fixed Fixed::operator++ (int) {
	const Fixed tmp(*this);
	this->num++;
	return tmp;
}

Fixed& Fixed::operator-- (void) {
	this->num--;
	return *this;
}

const Fixed Fixed::operator-- (int) {
	const Fixed tmp(*this);
	this->num--;
	return tmp;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Fixed::~Fixed() {}

/* -------------------------------------------------------------------------- */
/*                              Member Functions                              */
/* -------------------------------------------------------------------------- */
int Fixed::getRawBits(void) const {
	return num;
}

void Fixed::setRawBits(int const raw) {
	num = raw;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(num) / static_cast<float>((1 << bit)));
}
int Fixed::toInt(void) const {
	return (num / (1 << bit));
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a.toFloat() <= b.toFloat() ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return a.toFloat() <= b.toFloat() ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a.toFloat() >= b.toFloat() ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return a.toFloat() >= b.toFloat() ? a : b;
}


/* -------------------------------------------------------------------------- */
/*                              Global Functions                              */
/* -------------------------------------------------------------------------- */
std::ostream& operator<< (std::ostream& out, const Fixed& a) {
	out << a.toFloat();
	return out;
}
