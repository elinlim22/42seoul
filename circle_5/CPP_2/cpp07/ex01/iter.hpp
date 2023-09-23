#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T1, typename T2>
void iter(T1* address, size_t length, void(*func)(T2&)) {
	for (; length > 0; length--, address++) {
		func(*address);
	}
}

template <typename T>
void func(T& pos) {
	std::cout << ++pos << " ";
}

#endif
