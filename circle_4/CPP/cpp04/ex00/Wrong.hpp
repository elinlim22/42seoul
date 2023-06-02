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

#ifndef WRONG_HPP
#define WRONG_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		//Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal& a);
		//Destructor
		~WrongAnimal();
		//Operator overloaded
		WrongAnimal& operator= (const WrongAnimal& a);
		//Member functions
		void makeSound() const;
		std::string getType() const;
};

class WrongDog : public WrongAnimal {
	private:
		std::string type;
	public:
		//Constructors
		WrongDog();
		WrongDog(const WrongDog& a);
		//Destructor
		~WrongDog();
		//Operator overloaded
		WrongDog& operator= (const WrongDog& a);
		//Member functions
		void makeSound() const;
		std::string getType() const;
};

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
