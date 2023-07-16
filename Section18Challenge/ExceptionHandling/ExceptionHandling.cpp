#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"


int main()
{
    // Check if IllegalBalaanceException is working
    try 
    {
        Checking_Account testAccount{"Tony", -100.0};
    }
    catch (const IllegalBalanceException& ex)
    {
        std::cerr << "Couldn't create Account " << ex.what() << std::endl;
    }

    // Check if InsufficentFundsException is working
    try
    {
        Savings_Account testSavingAccount{ "Siegfried", 5000, 0.05 };
        testSavingAccount.withdraw(1000);
        std::cout << testSavingAccount << std::endl;
        testSavingAccount.withdraw(10000);
        std::cout << testSavingAccount << std::endl;
    }
    catch (const IllegalBalanceException& ex)
    {
        std::cerr << "Couldn't create Account " << ex.what() << std::endl;
    }
    catch (const InsufficentFundsException& ex2)
    {
        std::cerr << "Couldn't withdraw  to negative" << ex2.what() << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;

}
