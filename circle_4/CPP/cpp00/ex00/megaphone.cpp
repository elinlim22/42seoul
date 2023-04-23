/*
program goal :
	1. to make every letters uppercase
	2. if multiple arguments, join all
	3. if no argument, print * LOUD AND UNBEARABLE FEEDBACK NOISE *
*/

#include <iostream>
#include <string>

/* 메인함수 */
int main(int argc, char *argv[]) {
	std::string str;

	if (argc < 2) str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1; i < argc; i++) {
			str += std::string(argv[i]);
		}
		for (size_t i = 0; i < str.size(); i++) {
			str[i] = toupper(str[i]);
		}
	}

	std::cout << str << std::endl;

	return 0;
}
