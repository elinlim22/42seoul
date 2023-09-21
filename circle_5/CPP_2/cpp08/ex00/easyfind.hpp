#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
bool easyfind(T& first, int second) {
	typename T::iterator it = first.begin();
	for (; it != first.end(); ++it) {
		if (*it == second) return true;
	}
	return false;

	// typename T::iterator it = std::find(first.begin(), first.end(), second);
	// if (it == first.end() && *first.end() != second) return false;
	// else return true;
}

#endif
