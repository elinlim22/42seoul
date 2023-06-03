#ifndef POLYMORPHISM_HPP
#define POLYMORPHISM_HPP

#include "Brain.hpp"

class Animal {
	protected:
		std::string type;
	public:
		//Constructors
		Animal();
		Animal(const Animal& a);
		//Destructor
		virtual ~Animal();
		//Operator overloaded
		Animal& operator= (const Animal& a);
		//Member functions
		virtual void makeSound() const;
		virtual std::string getType() const;
};

class Dog : public Animal {
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

class Cat : public Animal {
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
