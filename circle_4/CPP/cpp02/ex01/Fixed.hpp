/*
	OCCF (모듈2부터)
		class A
		{
			A(); -> 기본생성자
			~A(); -> 기본소멸자
			A(const A &a); -> 복사생성자
			A &operator= (const A &a); -> 할당 연산자 오버로딩
		};
*/

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int num; //store the fixed-point number value
		static const int bit = 8; //store the number of fractional bits. always be the integer literal 8.
	public:
		Fixed();
		Fixed(const Fixed &a);
		Fixed(const int i);
		Fixed(const float i);
		Fixed& operator= (const Fixed &a);
		std::ostream& operator<< (const Fixed &a);
		~Fixed();
		int getRawBits(void) const; //returns the raw value of the fixed-point value
		void setRawBits(int const raw); //sets the raw value of the fixed-point number
		float toFloat(void) const;
		int toInt(void) const;
};

#endif
