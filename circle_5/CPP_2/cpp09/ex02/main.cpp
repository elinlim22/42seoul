#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
	if (argc < 2) return (static_cast<void>(std::cerr << "Error: Wrong input" << std::endl), -1);
	std::string input;
	for (int i = 1; i < argc; i++) {
		input += std::string(argv[i]);
		input += " ";
	}

	PmergeMe a;
	a.initData(input);
	a.MIsort();
	return 0;
}
