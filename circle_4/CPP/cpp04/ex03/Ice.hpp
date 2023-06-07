#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

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
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
