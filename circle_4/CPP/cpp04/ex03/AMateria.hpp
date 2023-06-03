#include <iostream>

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

// class Materia : public AMateria {
// 	private:
// 		std::string type;
// 	public:
// 		AMateria* clone() const override;
// 		void use(ICharacter& target) override;
// };

/* -------------------------------------------------------------------------- */
/*                        Interface class MateriaSource                       */
/* -------------------------------------------------------------------------- */
class IMateriaSource {
	public:
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const& type) = 0;
};

class MateriaSource : public IMateriaSource {
	private:
	public:
		//Constructors
		MateriaSource();
		MateriaSource(const MateriaSource& a);
		//Destructor
		virtual ~MateriaSource();
		//Operator overloaded
		MateriaSource& operator= (const MateriaSource& a);

		//Member functions
		void learnMateria(AMateria*) override;
		AMateria* createMateria(std::string const& type) override;
};

#endif
