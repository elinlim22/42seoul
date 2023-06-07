#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	private:
	public:
		//Constructors
		Cure();
		Cure(const Cure& a);
		//Destructor
		virtual ~Cure();
		//Operator overloaded
		Cure& operator= (const Cure& a);
		//Member functions
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
