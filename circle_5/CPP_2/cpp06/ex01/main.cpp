#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data* d = new Data();
	std::cout << "Original Data: " << d->getData() << std::endl;
	std::cout << "Data* d address: " << d << std::endl;

	uintptr_t ptr = Serializer::serialize(d);
	std::cout << "uintptr_t ptr: " << ptr << std::endl;

	Data* ret = Serializer::deserialize(ptr);
	std::cout << "Data* ret address: " << ret << std::endl;

	std::cout << "Casted Data: " << ret->getData() << std::endl;

	delete d;
	return 0;
}
