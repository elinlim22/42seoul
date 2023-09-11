#include "ScalarConverter.hpp"

std::string printFlag(int f) {
	switch (f) {
		case CFLAG:
			return "Char";
		case IFLAG:
			return "Int";
		case FFLAG:
			return "Float";
		case DFLAG:
			return "Double";
		default:
			return "NO TYPE";
	}
}

int main(int argc, char* argv[]) {
	(void)argc;
	std::string input = std::string(argv[1]);
	ScalarConverter C;
	char returnChar = 0;
	int returnInt = 0;
	float returnFloat = 0.0f;
	double returnDouble = 0.0;

	/*
		1. 판단 -> 플래그?
		2. 출력할 수 없는 값들 예외처리
		3. 값으로 모두 static cast

	*/

	try {
		C.checkType(input);
		/*
			출력할 수 없는 값들 예외처리
		*/
		std::cout << "----Type : " << printFlag(C.getFlag()) << "----\n";
		switch (C.getFlag()) {
			case CFLAG:
				returnChar = C.convertToChar(input);
				break ;
			case IFLAG:
				returnInt = C.convertToInt(input);
				break ;
			case FFLAG:
				returnFloat = C.convertToFloat(input);
				break ;
			case DFLAG:
				returnDouble = C.convertToDouble(input);
				break ;
			default:
				throw std::runtime_error("Nothing flagged");
		}
		/*
			값으로 모두 static cast
			주어진 것 : flag, 변수4개
			흐름 : 플래그에 맞게 ... 어... Double로 먼저 받기?
		*/
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}

	std::cout << "char: " << returnChar << std::endl;
	std::cout << "int: " << returnInt << std::endl;
	std::cout << "float: " << returnFloat << 'f' << std::endl;
	std::cout << "double: " << returnDouble << std::endl;

	return 0;

}
