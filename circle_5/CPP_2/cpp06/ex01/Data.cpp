#include "Data.hpp"

/* -------------------------------------------------------------------------- */
/*                                    OCCP                                    */
/* -------------------------------------------------------------------------- */
Data::Data() : data(42) {}

Data::Data(const Data& a) {
	*this = a;
}

Data& Data::operator= (const Data& a) {
	if (this != &a) {
		this->data = a.data;
	}
	return *this;
}

Data::~Data() {}

/* -------------------------------------------------------------------------- */
/*                               Member function                              */
/* -------------------------------------------------------------------------- */
int Data::getData() const {
	return this->data;
}
