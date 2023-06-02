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

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:

	public:
		//Constructors
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &a);
		//Destructor
		~ScavTrap();
		//Operator overloaded
		ScavTrap &operator= (const ScavTrap &a);
		//Member functions
		void guardGate();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void action_attack(ScavTrap& target);
		void callStatus(ScavTrap& a);
};

#endif
