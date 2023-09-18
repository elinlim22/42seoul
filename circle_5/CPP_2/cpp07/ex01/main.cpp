#include "iter.hpp"

int main() {
	int arr[5] = {0, 1, 2, 3, 4};

	iter<int>(arr, 5, func<int>);

	return 0;
}
