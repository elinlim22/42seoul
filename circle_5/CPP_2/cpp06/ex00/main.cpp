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
	// char returnChar = 0;
	// int returnInt = 0;
	// float returnFloat = 0.0f;
	// double returnDouble = 0.0;

	/*
		1. 판단 -> 플래그?
		2. 출력할 수 없는 값들 예외처리
		3. 값으로 모두 static cast

	*/

	try {
		// C.checkPrint(input);
		C.checkType(input);
		std::cout << "----Type : " << printFlag(C.getFlag()) << "----\n";
		C.doCast(input);
		/*
			출력할 수 없는 값들 예외처리
		*/
		// switch (C.getFlag()) {
		// 	case CFLAG:
		// 		C.returnChar = C.convertToChar(input);
		// 		break ;
		// 	case IFLAG:
		// 		C.returnInt = C.convertToInt(input);
		// 		break ;
		// 	case FFLAG:
		// 		C.returnFloat = C.convertToFloat(input);
		// 		break ;
		// 	case DFLAG:
		// 		C.returnDouble = C.convertToDouble(input);
		// 		break ;
		// 	default:
		// 		throw std::runtime_error("Nothing flagged");
		// }
		/*
			값으로 모두 static cast
			주어진 것 : flag, 변수4개
			흐름 : 플래그에 맞게 ... 어... Double로 먼저 받기?
		*/
	} catch (ScalarConverter::printException& e) {
		e.ePrint();
		// std::exit(EXIT_FAILURE);
	}

	C.printValue();

	return 0;

}
