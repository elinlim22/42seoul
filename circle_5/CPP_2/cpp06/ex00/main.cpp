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
		std::cout << "Error: too many input" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	std::string input = std::string(argv[1]);
	ScalarConverter C;

	C.checkType(input);
	// std::cout << "----Type : " << printFlag(C.getFlag()) << "----\n";
	C.doCast(input);
	C.printValue();

	return 0;
}
