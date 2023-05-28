#include <iostream>

// Function declaration
void changeCalc(int inputAmount);

int main()
{
	std::cout << "US Dollar change calculator \n\n";
	std::cout << "Enter an amount in cents: ";
	int amountChange{};
	std::cin >> amountChange;
	
	// check if amount is greater than 0
	if (amountChange >=0)
	{ 
		changeCalc(amountChange);
	}
	else
	{
		std::cout << "You have inserted a negative value!\n";
	}

}

void changeCalc(int inputAmount)
{
	int remainder{}, dollar{}, quater{}, dime{}, nickel{}, penny{};
	const int dollarInCents{ 100 }, quaterInCents{ 25 }, dimeInCents{ 10 },
		nickelInCents{ 5 }, pennyInPenny{ 1 };

	dollar = {inputAmount / dollarInCents };
	remainder = { inputAmount % dollarInCents };

	quater = { remainder / quaterInCents };
	remainder = { remainder % quaterInCents };

	dime = { remainder / dimeInCents };
	remainder = { remainder % dimeInCents };

	nickel = { remainder / nickelInCents };
	remainder = { remainder % nickelInCents };

	penny = { remainder };

	// Output result
	std::cout << " You can provide this change as follows:\n";
	std::cout << "\t dollars: \t" << dollar << "\n";
	std::cout << "\t quaters: \t" << quater << "\n";
	std::cout << "\t dimes: \t" << dime << "\n";
	std::cout << "\t nickels: \t" << nickel << "\n";
	std::cout << "\t pennies: \t" << penny << "\n";

}