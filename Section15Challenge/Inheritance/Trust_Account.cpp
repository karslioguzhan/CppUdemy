#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
	:Savings_Account(name, balance, int_rate)
{
}

bool Trust_Account::deposit(double amount)
{
	if (amount < 0)
	{
		return false;
	}
	else if (amount >= bonusThreshold)
	{
		balance += (amount + bonus);
	}
	else
	{
		balance += amount;
	}
	return true;
}

bool Trust_Account::withdraw(double amount)
{
	bool checkLegitWithdraw{ (balance - amount <= 0)
		|| availableNumberOfWithdraw <= 0 
		|| (amount > (balance*maxWithdrawRate))};
	if (checkLegitWithdraw)
	{
		return false;
	}
	balance -= amount;
	--availableNumberOfWithdraw;
	return true;
}
