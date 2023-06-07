#ifndef CAT_HPP
#define CAT_HPP

#include "AbstAnimal.hpp"
#include "Brain.hpp"

class Cat : public AbstAnimal {
	private:
		std::string type;
		Brain* ideas;
	public:
		//Constructors
		Cat();
		Cat(const Cat& a);
		//Destructor
		~Cat();
		//Operator overloaded
		Cat& operator= (const Cat& a);
		//Member functions
		void makeSound() const;
		std::string getType() const;
};

#endif
