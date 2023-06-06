#ifndef POLYMORPHISM_HPP
#define POLYMORPHISM_HPP

#include "Brain.hpp"

class AbstAnimal {
	protected:
		std::string type;
	public:
		//Constructors
		AbstAnimal();
		AbstAnimal(const AbstAnimal& a);
		//Destructor
		virtual ~AbstAnimal();
		//Operator overloaded
		AbstAnimal& operator= (const AbstAnimal& a);
		//Member functions
		virtual void makeSound() = 0;
		virtual std::string getType() const;
};

class Dog : public AbstAnimal {
	private:
		std::string type;
		Brain* ideas;
	public:
		//Constructors
		Dog();
		Dog(const Dog& a);
		//Destructor
		~Dog();
		//Operator overloaded
		Dog& operator= (const Dog& a);
		//Member functions
		void makeSound() const;
		std::string getType() const;
};

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
