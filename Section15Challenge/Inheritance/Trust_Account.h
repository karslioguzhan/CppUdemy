/*
    2. Add a Trust account class to the Account hierarchy
        A Trust account has a name, a balance, and an interest rate
        The Trust account deposit works just like a savings account deposit.
        However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.

        The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance.
        You don't have to keep track of calendar time for this application, just make sure the 4th withdrawal fails :)
*/
#pragma once
#include <string>
#include "Savings_Account.h"

class Trust_Account :
    public Savings_Account
{
private:
    static constexpr const char* def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double maxWithdrawRate{ 0.2 };
    static constexpr int bonus{ 50 };
    static constexpr double bonusThreshold{ 5000 };
    int availableNumberOfWithdraw{ 3 };

public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    bool withdraw(double amount);


};

