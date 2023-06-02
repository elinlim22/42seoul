/*
	OCCF (모듈2부터)
		class A
		{
			A(); -> 기본생성자
			~A(); -> 기본소멸자
			A(const A &a); -> 복사생성자
			A &operator= (const A &a); -> 할당 연산자 오버로딩
		};
*/

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
	private:

	public:
		//Constructors
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap &a);
		//Destructor
		~FragTrap();
		//Operator overloaded
		FragTrap &operator= (const FragTrap &a);
		//Member functions
		// void guardGate();
		void highFivesGuys(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void action_attack(FragTrap& target);
		void callStatus(FragTrap& a);
};

#endif
