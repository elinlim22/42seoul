#ifndef MATERASOURCE_HPP
#define MATERASOURCE_HPP

#include "IMateriaSource.hpp"
class AMateria;

class MateriaSource : public IMateriaSource {
	private:
		AMateria* list[4];
	public:
		//Constructors
		MateriaSource();
		MateriaSource(const MateriaSource& a);
		//Destructor
		virtual ~MateriaSource();
		//Operator overloaded
		MateriaSource& operator= (const MateriaSource& a);

		//Member functions
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const& type);
};

#endif
