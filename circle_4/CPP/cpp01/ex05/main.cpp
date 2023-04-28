#include "Harl.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) { std::cout << "Error: arguments error" << std::endl; return -1; }

	std::string level = std::string(argv[1]);
	Harl temp;
	temp.complain(level);

	return 0;
}
