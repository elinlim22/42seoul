#include <iostream>
#include <string>

// using namespace std;

class Myclass
{
	private:
	std::string str = "apple";

	public:
	void print()
	{
		std::cout << str << std::endl;
	}
};


int	main()
{
	Myclass class1;

	class1.print();

	return 0;
}
