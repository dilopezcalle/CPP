#include "FragTrap.hpp"

// ===== Constructors =====
FragTrap::FragTrap()
{
	this->setName("NULL");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->_name
	<< " default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "FragTrap " << this->_name 
	<< " copy constructor called";
	*this = src;
	return ;
}

FragTrap::FragTrap(std::string name)
{
	setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->_name 
	<< " constructor called" << std::endl;
	return ;
}

// ===== Destructor =====
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
	return ;
}

// ===== Operators =====
FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
	return (*this);
}

// ===== Methods =====
void FragTrap::highFivesGuys(void)
{
	std::cout << "Can you give a high five?" << std::endl;
	return ;
}