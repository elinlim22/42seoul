#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {
	int rd = std::rand() % 3;
	Base* ret;
	switch (rd) {
		case 0:
			ret = new A();
			break ;
		case 1:
			ret = new B();
			break ;
		case 2:
			ret = new C();
			break ;
	}
	return ret;
}

void identify(Base* p) {
	A* APtr = dynamic_cast<A*>(p);
	if (APtr != NULL) {
		std::cout << "Type is A" << std::endl;
		return ;
	}
	B* BPtr = dynamic_cast<B*>(p);
	if (BPtr) {
		std::cout << "Type is B" << std::endl;
		return ;
	}
	C* CPtr = dynamic_cast<C*>(p);
	if (CPtr) {
		std::cout << "Type is C" << std::endl;
		return ;
	}
	std::cout << "Error: type not found" << std::endl;
}

void identify(Base& p) {
	try {
		A AIns = dynamic_cast<A&>(p);
		std::cout << "Type is A" << std::endl;
		return ;
	} catch (std::exception& e) {}
	try {
		B BIns = dynamic_cast<B&>(p);
		std::cout << "Type is B" << std::endl;
		return ;
	} catch (std::exception& e) {}
	try {
		C CIns = dynamic_cast<C&>(p);
		std::cout << "Type is C" << std::endl;
		return ;
	} catch (std::exception& e) {}
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));
	Base* rdClass = generate();
	std::cout << "Pointer based check: ";
	identify(rdClass);
	std::cout << "Reference based check: ";
	identify(*rdClass);

	Base* rdClass2 = generate();
	std::cout << "Pointer based check: ";
	identify(rdClass2);
	std::cout << "Reference based check: ";
	identify(*rdClass2);

	Base* rdClass3 = generate();
	std::cout << "Pointer based check: ";
	identify(rdClass3);
	std::cout << "Reference based check: ";
	identify(*rdClass3);

	delete rdClass;
	delete rdClass2;
	delete rdClass3;

	return 0;
}
