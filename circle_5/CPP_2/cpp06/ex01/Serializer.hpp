#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

class Data;

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& a);
		Serializer& operator= (const Serializer& a);
		virtual ~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
