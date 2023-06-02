/*
	OCCF (모듈2부터)
		class A
		{
			A(); -> 기본생성자
			A(const A& a); -> 복사생성자
			~A(); -> 기본소멸자
			A &operator= (const A& a); -> 할당 연산자 오버로딩
		};
*/

#ifndef POLYMORPHISM_HPP
#define POLYMORPHISM_HPP

#include <iostream>

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
		// void makeSound();
};

class Cat : public Animal {
	private:
		std::string type;
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
		// void makeSound();
};

#endif
