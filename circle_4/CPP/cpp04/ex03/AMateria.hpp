#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

/* -------------------------------------------------------------------------- */
/*                           Abstract class Materia                           */
/* -------------------------------------------------------------------------- */
class AMateria {
	protected:
		std::string type;
	public:
		//Constructors
		AMateria();
		AMateria(const AMateria& a);
		AMateria(std::string const& type);
		//Destructor
		virtual ~AMateria();
		//Operator overloaded
		AMateria& operator= (const AMateria& a);
		//Member functions
		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};

#endif
