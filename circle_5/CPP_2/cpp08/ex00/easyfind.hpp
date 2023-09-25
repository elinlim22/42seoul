#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
bool easyfind(T& container, int target) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		if (*it == target) return true;
	}
	return false;
}

#endif
