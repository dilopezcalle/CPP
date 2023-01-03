#include "DiamondTrap.hpp"

// ===== Constructors =====
DiamondTrap::DiamondTrap()
{
	this->_name = "NULL";
	ClapTrap::setName("NULL_clap_trap");
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(50);
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "DiamondTrap " << this->_name
	<< " default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	std::cout << "DiamondTrap " << this->_name 
	<< " copy constructor called";
	*this = src;
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	ClapTrap::setName(name + "_clap_trap");
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(50);
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "DiamondTrap " << this->_name 
	<< " constructor called" << std::endl;
	return ;
}

// ===== Destructor =====
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
	return ;
}

// ===== Operators =====
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	this->_name = src.getDiamondName();
	ClapTrap::setName(src.getName());
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
}

// ===== Getters =====
std::string	DiamondTrap::getDiamondName(void) const
{
	return (this->_name);
}

// ===== Methods =====
void	DiamondTrap::whoAmI(void)
{
	std::cout << "name:\t\t" << this->_name << std::endl;
	std::cout << "clapTrap name:\t" << ClapTrap::getName() << std::endl;
	return ;
}