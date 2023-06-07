#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	private:
		std::string type;
	public:
		//Constructors
		Cat();
		Cat(const Cat& a);
		//Destructor
		virtual ~Cat();
		//Operator overloaded
		Cat& operator= (const Cat& a);
		//Member functions
		void makeSound() const;
		std::string getType() const;
};

#endif
