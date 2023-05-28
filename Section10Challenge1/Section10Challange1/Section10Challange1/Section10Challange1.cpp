// Section10Challange1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// global variables
std::string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
std::string key     {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

// function prototypes
std::string encryptMessage(std::string clearMessage);
void decryptMessage(std::string encryptedMessage);


int main()
{
	// get user text
	std::cout << "Enter your secret message: ";
	std::string clearMessage;
	std::getline(std::cin, clearMessage);
	// encrypt message
	std::string encryptedMessage{ encryptMessage(clearMessage) };
	// decrypt message
	decryptMessage(encryptedMessage);

	return 0;
	
}


std::string encryptMessage(std::string clearMessage)
{
	std::string encryptedMessage{ clearMessage };
	for (size_t numCharClear{0}; numCharClear < clearMessage.length(); ++numCharClear)
	{
		// get the position in alphabet for swapping the letter with the key
		size_t swapPosition{ alphabet.find(clearMessage.at(numCharClear)) };
		if (swapPosition != std::string::npos)
		{
			encryptedMessage.at(numCharClear) = key.at(swapPosition);
		}
	}
	std::cout << "Encrypting message...\n";
	std::cout << "Encrypted message: " << encryptedMessage << std::endl;
	return encryptedMessage;
}

void decryptMessage(std::string encryptedMessage)
{
	std::string decryptedMessage{ encryptedMessage };
	for (size_t numCharEn{ 0 }; numCharEn < encryptedMessage.length(); ++numCharEn)
	{
		// get the position in key for swapping the letter with the alphabet
		size_t swapPosition{ key.find(encryptedMessage.at(numCharEn)) };
		if (swapPosition != std::string::npos)
		{
			decryptedMessage.at(numCharEn) = alphabet.at(swapPosition);
		}
	}
	std::cout << "Decrypting message...\n";
	std::cout << "Decrypted message: " << decryptedMessage << std::endl;

}

