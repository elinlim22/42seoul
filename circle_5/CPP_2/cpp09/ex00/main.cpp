#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Error: One input file required to execute" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::string inputFile(argv[1]);

	BitcoinExchange btc;
	btc.execute(inputFile);
	return 0;
}
