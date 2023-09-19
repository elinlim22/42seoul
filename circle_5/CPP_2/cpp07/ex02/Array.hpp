#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array {
	private:
		T* arr;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& a);
		~Array();
		Array& operator= (const Array& a);
		T& operator[] (const size_t& a) const;
		size_t size() const;
		class OutOfBounds : public std::exception {
			virtual const char* what() const throw();
		};
};

#include "Array.tpp"
#endif
