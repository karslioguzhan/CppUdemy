#pragma once

class InsufficentFundsException : public std::exception
{
public:
	InsufficentFundsException() noexcept = default;
	~InsufficentFundsException() = default;
	virtual const char* what() const noexcept
	{
		return "Insufficent Funds exception";
	}
};