#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	private:
		std::string type;
	public:
		//Constructors
		WrongCat();
		WrongCat(const WrongCat& a);
		//Destructor
		~WrongCat();
		//Operator overloaded
		WrongCat& operator= (const WrongCat& a);
		//Member functions
		void makeSound() const;
		std::string getType() const;
};

#endif
