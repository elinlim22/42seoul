#include "Serializer.hpp"

/* -------------------------------------------------------------------------- */
/*                                    OCCP                                    */
/* -------------------------------------------------------------------------- */
Serializer::Serializer() {}

Serializer::Serializer(const Serializer& a) {
	static_cast<void>(a);
}

Serializer& Serializer::operator= (const Serializer& a) {
	static_cast<void>(a);
	return *this;
}

Serializer::~Serializer() {}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
