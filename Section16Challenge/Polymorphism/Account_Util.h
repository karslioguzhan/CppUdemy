#include <vector>
#include "Account.h"

// Utility helper functions for Account and derived classes

void display(const std::vector<Account*>& accounts);
void deposit(std::vector<Account*>& accounts, double amount);
void withdraw(std::vector<Account*>& accounts, double amount);
