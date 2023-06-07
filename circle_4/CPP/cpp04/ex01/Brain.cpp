#include "Brain.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Brain::Brain() {
	std::cout << "<<< Brain Constructor called >>>" << std::endl;
}

Brain::Brain(const Brain& a) {
	std::cout << "<<< Brain Copy Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Brain::~Brain() {
	std::cout << "<<< Brain Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
Brain& Brain::operator= (const Brain& a) {
	if (this != &a) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = a.ideas[i];
		}
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
const std::string* Brain::getBrain() const {
	return this->ideas;
}
