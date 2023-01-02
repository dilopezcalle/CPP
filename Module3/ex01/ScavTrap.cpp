#include <iostream>

#include "ScavTrap.hpp"

// ===== Constructors =====
ScavTrap::ScavTrap()
{
	this->setName("NULL");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << this->_name
	<< " default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "ScavTrap " << this->_name 
	<< " copy constructor called";
	*this = src;
	return ;
}

ScavTrap::ScavTrap(std::string name)
{
	setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << this->_name 
	<< " constructor called" << std::endl;
	return ;
}

// ===== Destructor =====
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
	return ;
}

// ===== Operators =====
ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
	return (*this);
}

// ===== Methods =====
void	ScavTrap::attack(std::string const &target)
{
	this->_hitPoints--;
	std::cout << "ScavTrap " << this->_name << " ataca a " << target << ", causando "
	<< this->_attackDamage << " de puntos de daño!" << std::endl;
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name 
	<< " have enterred in Gate keeper mode" << std::endl;
	return ;
}