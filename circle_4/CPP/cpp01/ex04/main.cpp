#include "Sed.hpp"

int main(int argc, char *argv[]) {
	if (argc != 4) { std::cout << "Argument Error" << std::endl; return -1; }
	else {
		std::string filename = std::string(argv[1]);
		std::string s1 = std::string(argv[2]);
		std::string s2 = std::string(argv[3]);
		std::string buf;

		std::ifstream infile(filename);

		if (!infile.is_open()) {
			std::cout << "Error: cannot open file " << filename << std::endl;
			return -1;
		}
		std::ofstream outfile(filename + ".replace");
		while (std::getline(infile, buf) && infile.good())
		{
			size_t index = buf.find(s1);
			if (index != std::string::npos) {
				buf.erase(index, index + s1.length());
				buf.insert(index, s2);
			}
			outfile << buf << std::endl;
		}

		infile.close();
		outfile.close();
	}
	return 0;
}
