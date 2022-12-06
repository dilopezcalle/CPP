#include <iostream>
#include <iomanip>

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	std::cout << "Account Empty Contructor" << std::endl;
	return ;
}

Account::Account( int initial_deposit )
{
	this->_displayTimestamp();
	this->_amount = initial_deposit;
	std::cout << "index:" << Account::_nbAccounts << ";amount:" << this->_amount << ";created" << std::endl;
	this->_accountIndex = Account::_nbAccounts;
	this->_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	return ;
}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";closed" << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);
	struct tm * now = localtime( & t );
	std::cout << '[' << (now->tm_year + 1900)
	<< std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
	<< std::setw(2) << std::setfill('0') << now->tm_mday
	<< '_'
	<< std::setw(2) << std::setfill('0') << now->tm_hour
	<< std::setw(2) << std::setfill('0') << now->tm_min
	<< std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
}

int	Account::getNbAccounts(void)
{
	std::cout << "getNbAccounts" << std::endl;
	return (0);
}

int	Account::getTotalAmount(void)
{
	std::cout << "getTotalAmount" << std::endl;
	return (0);
}

int	Account::getNbDeposits(void)
{
	std::cout << "getNbDeposits" << std::endl;
	return (0);
}

int	Account::getNbWithdrawals(void)
{
	std::cout << "getNbWithdrawals" << std::endl;
	return (0);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "account:" << Account::_nbAccounts 
	<< ";total:" << Account::_totalAmount 
	<< ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
	return ;
}


void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposit:" << deposit
	<< ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals ++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";withdrawal:" << withdrawal
	<< ";amount:" << _amount
	<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	std::cout << "checkAmount" << std::endl;
	return (0);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}
