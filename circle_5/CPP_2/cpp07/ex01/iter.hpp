#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T* address, T length, void(*func)(T&)) {
	for (; length > 0; length--, address++) {
		func(*address);
	}
}

template <typename T>
void func(T& pos) {
	std::cout << ++pos << " ";
}

#endif
