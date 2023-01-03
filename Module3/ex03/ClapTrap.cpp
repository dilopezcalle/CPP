#include "ClapTrap.hpp"

// ===== Constructors =====
ClapTrap::ClapTrap() : _name("NULL"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name
	<< " default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap " << this->_name
	<< " copy constructor called";
	*this = src;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name
	<< " constructor called" << std::endl;
	return ;
}

// ===== Destructor =====
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name
	<< " destructor called" << std::endl;
	return ;
}

// ===== Operators =====
ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
}

// ===== Getters =====
std::string	ClapTrap::getName(void) const
{ return (this->_name); }

unsigned int	ClapTrap::getHitPoints(void) const
{ return (this->_hitPoints); }

unsigned int	ClapTrap::getEnergyPoints(void) const
{ return (this->_energyPoints); }

unsigned int	ClapTrap::getAttackDamage(void) const
{ return (this->_attackDamage); }

// ===== Setters =====
void	ClapTrap::setName(std::string name)
{ this->_name = name; }

void	ClapTrap::setHitPoints(unsigned int hitPoints)
{ this->_hitPoints = hitPoints; }

void	ClapTrap::setEnergyPoints(unsigned int energyPoints)
{ this->_energyPoints = energyPoints; }

void	ClapTrap::setAttackDamage(unsigned int attackDamage)
{ this->_attackDamage = attackDamage; }

// ===== Methods =====
void	ClapTrap::attack(std::string const &target)
{
	this->_hitPoints--;
	std::cout << "ClapTrap " << this->_name << " ataca a " << target << ", causando "
	<< this->_attackDamage << " de puntos de daño!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_energyPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " perdió "
	<< amount << " puntos de energía" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_energyPoints += amount;
	std::cout << "ClapTrap " << this->_name << " ganó "
	<< amount << " puntos de energía" << std::endl;
	return ;
}

void	ClapTrap::displayStatus(void)
{
	std::cout << "Status " << this->_name << ":"
	<< "\nHit points: " << this->_hitPoints
	<< "\nEnergy points: " << this->_energyPoints
	<< "\nAttack damege: " << this->_attackDamage
	<< std::endl;
}
