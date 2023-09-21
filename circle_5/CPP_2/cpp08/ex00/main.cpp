#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main() {
	std::vector<int> arrV;
	std::deque<int> arrD;
	std::list<int> arrL;

	for (int i = 0; i < 5; i++) {
		arrV.push_back(i + 1);
		arrD.push_back(i);
		arrL.push_back(i + 1);
	}
	std::cout << easyfind(arrV, 5) << std::endl;
	std::cout << easyfind(arrD, 5) << std::endl;
	std::cout << easyfind(arrL, 5) << std::endl;

	return 0;
}
