#include "Account.hpp"

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
	_accountIndex = Account::getNbAccounts();
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	// to access a static member variable it must first be assigned below the Class
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
    // Print log of what was done
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
};

Account::~Account()
{
    Account::_nbAccounts -= 1;
	Account::_totalAmount -= _amount;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
};

Account::Account()
{

};

int Account::getNbAccounts(void) // static
{
    return _nbAccounts;
}

int Account::getTotalAmount(void) // static
{
    return _totalAmount;
}

int Account::getNbDeposits(void) // static
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) // static
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}


void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
	_amount += deposit;
	_nbDeposits += 1;
	// and update total
	_totalAmount += deposit;
	_totalNbDeposits += 1;
    // post-deposit loglines
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _totalNbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    // post-deposit loglines
    std::cout << "withdrawl:";
    if (_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    else
    {
        _amount -= withdrawal;
        _nbWithdrawals += 1;
        // and update total
        _totalAmount -= withdrawal;
        _totalNbWithdrawals += 1;
        std::cout << withdrawal << ";";
        std::cout << "amount:" << _amount << ";";
        std::cout << "nb_withdrwals:" << _totalNbWithdrawals << std::endl;
        return (true);
    }
}
int		Account::checkAmount( void ) const
{
    return(_amount);
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::cout << "[20250507_160201] ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;