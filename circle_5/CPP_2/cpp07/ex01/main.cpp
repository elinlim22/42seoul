#include "iter.hpp"

int main() {
	int arr[5] = {0, 1, 2, 3, 4};
	char arr2[5] = {'a', 'b', 'c', 'd', 'e'};

	iter<int>(arr, 5, func<int>);
	iter<char>(arr2, 5, func<char>);

	return 0;
}
