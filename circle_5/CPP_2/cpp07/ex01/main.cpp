#include "iter.hpp"

int main() {
	int arr[5] = {0, 1, 2, 3, 4};
	char arr2[5] = {'a', 'b', 'c', 'd', 'e'};

	iter<int>(arr, 5, func<int>);
	std::cout << std::endl;
	iter<char>(arr2, 5, func<char>);
	std::cout << std::endl;

	return 0;
}
