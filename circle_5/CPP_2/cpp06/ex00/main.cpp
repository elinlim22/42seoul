#include "ScalarConverter.hpp"

// std::string printFlag(int f) {
// 	switch (f) {
// 		case CFLAG:
// 			return "Char";
// 		case IFLAG:
// 			return "Int";
// 		case FFLAG:
// 			return "Float";
// 		case DFLAG:
// 			return "Double";
// 		default:
// 			return "NO TYPE";
// 	}
// }

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Error: one input required" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	std::string input = std::string(argv[1]);

	ScalarConverter::checkType(input);
	// std::cout << "----Type : " << printFlag(ScalarConverter::getFlag()) << "----\n";
	ScalarConverter::convert(input);
	ScalarConverter::printValue();

	return 0;
}
