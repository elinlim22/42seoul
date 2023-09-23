#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
bool easyfind(T& first, int second) {
	typename T::iterator it = first.begin();
	for (; it != first.end(); ++it) {
		if (*it == second) return true;
	}
	return false;
}

#endif
