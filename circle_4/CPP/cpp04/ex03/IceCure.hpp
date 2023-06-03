#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	private:
	public:
		//Constructors
		Ice();
		Ice(const Ice& a);
		//Destructor
		virtual ~Ice();
		//Operator overloaded
		Ice& operator= (const Ice& a);

		//Member functions
		AMateria* clone() const override;
};

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
		AMateria* clone() const override;
};

#endif
