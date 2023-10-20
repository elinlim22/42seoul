#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int target) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		if (*it == target) return it;
	}
	return container.end();
}

#endif
