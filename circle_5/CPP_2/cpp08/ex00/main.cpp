#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main() {
	std::vector<int> arrV;
	std::deque<int> arrD;
	std::list<int> arrL;

	for (int i = 0; i < 5; i++) {
		arrV.push_back(i + 1); // 1 2 3 4 5
		arrD.push_back(i); // 0 1 2 3 4
		arrL.push_back(i + 1); // 1 2 3 4 5
	}
	std::vector<int>::iterator it = easyfind(arrV, 5);
	if (it == arrV.end()) std::cout << "Not found" << std::endl;
	else std::cout << *it << std::endl; // 5

	std::deque<int>::iterator it2 = easyfind(arrD, 5);
	if (it2 == arrD.end()) std::cout << "Not found" << std::endl;
	else std::cout << *it2 << std::endl; // Not found

	std::list<int>::iterator it3 = easyfind(arrL, 0);
	if (it3 == arrL.end()) std::cout << "Not found" << std::endl;
	else std::cout << *it3 << std::endl; // Not found

	return 0;
}
