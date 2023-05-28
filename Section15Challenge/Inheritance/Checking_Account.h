/*
    1. Add a Checking account class to the Account hierarchy
        A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
        Every withdrawal transaction will be assessed this flat fee.
*/ 
#pragma once
#include "Account.h"
class Checking_Account :
    public Account
{
private:
    static constexpr double withdrawFee{ 1.5 };
    static constexpr const char *defaultName = "CheckingAccount";
    static constexpr double defaultBalance{ 0 };
public:
    //Constructor
    Checking_Account(std::string name = defaultName, double balance = defaultBalance);
    bool withdraw(double amount);

};

