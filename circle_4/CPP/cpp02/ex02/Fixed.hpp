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
#include <cmath>

class Fixed {
	private:
		int num; //store the fixed-point number value
		static const int bit = 8; //store the number of fractional bits. always be the integer literal 8.
	public:
		/* -------------------------------------------------------------------------- */
		/*                                Constructors                                */
		/* -------------------------------------------------------------------------- */
		Fixed();
		Fixed(const Fixed& a);
		Fixed(const int i);
		Fixed(const float f);
		Fixed& operator= (const Fixed& a);

		/* -------------------------------------------------------------------------- */
		/*                              Operator overload                             */
		/* -------------------------------------------------------------------------- */
		// 6 comparison operators
		// Fixed& operator= (const Fixed& a);
		bool operator> (const Fixed& a);
		bool operator< (const Fixed& a);
		bool operator>= (const Fixed& a);
		bool operator<= (const Fixed& a);
		bool operator== (const Fixed& a);
		bool operator!= (const Fixed& a);
		// 4 arithmetic operators
		Fixed operator+ (const Fixed& a);
		Fixed operator- (const Fixed& a);
		Fixed operator* (const Fixed& a);
		Fixed operator/ (const Fixed& a);
		// 4 increment/decrement operators
		Fixed& operator++ (void);
		const Fixed operator++ (int);
		Fixed& operator-- (void);
		const Fixed operator-- (int);


		/* -------------------------------------------------------------------------- */
		/*                                 Destructor                                 */
		/* -------------------------------------------------------------------------- */
		~Fixed();

		/* -------------------------------------------------------------------------- */
		/*                              Member Functions                              */
		/* -------------------------------------------------------------------------- */
		// previous
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		// added
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<< (std::ostream& out, const Fixed& a);

#endif
