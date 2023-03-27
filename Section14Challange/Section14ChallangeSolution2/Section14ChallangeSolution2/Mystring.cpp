#include <iostream>
#include <cstring>
#include "Mystring.h"
#pragma warning(disable:4996) // Visual studio doesn't allow strcpy for unsafety (Workaround)

// No-args constructor
Mystring::Mystring()
    : str{ nullptr } {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char* s)
    : str{ nullptr } {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring& source)
    : str{ nullptr } {
    str = new char[strlen(source.str) + 1];
    std::strcpy(str, source.str);
    //       std::std::cout << "Copy constructor used" << std::std::endl;

}

// Move constructor
Mystring::Mystring(Mystring&& source)
    :str(source.str) {
    source.str = nullptr;
    //        std::std::cout << "Move constructor used" << std::std::endl;
}

// Destructor
Mystring::~Mystring() {
    delete[] str;
}

// Copy assignment
Mystring& Mystring::operator=(const Mystring& rhs) {
    //    std::std::cout << "Using copy assignment" << std::std::endl;

    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring& Mystring::operator=(Mystring&& rhs) {
    //   std::std::cout << "Using move assignment" << std::std::endl;
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return strlen(str); }
const char* Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Mystring& rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream& operator>>(std::istream& in, Mystring& rhs) {
    char* buff = new char[1000];
    in >> buff;
    rhs = Mystring{ buff };
    delete[] buff;
    return in;
}

Mystring operator-(const Mystring& obj)
{
    char* tempString = new char[std::strlen(obj.str) + 1];
    std::strcpy(tempString, obj.str);
    for (size_t numChar{ 0 }; numChar < std::strlen(obj.str); ++numChar)
    {
        tempString[numChar] = std::tolower(obj.str[numChar]);
    }
    Mystring tempObj{ tempString };
    delete[] tempString;
    return tempObj;
}

bool operator==(const Mystring lhs, const Mystring rhs)
{
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring lhs, const Mystring rhs)
{
    return (std::strcmp(lhs.str, rhs.str) != 0);
}

bool operator<(const Mystring lhs, const Mystring rhs) 
{
    return (std::strlen(lhs.str) < std::strlen(rhs.str));
}

bool operator>(const Mystring lhs, const Mystring rhs)
{
    return (std::strlen(lhs.str) > std::strlen(rhs.str));
}

Mystring operator+(const Mystring& lhs, const Mystring& rhs)
{
    char* tempString = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(tempString, lhs.str);
    std::strcat(tempString, rhs.str);
    Mystring tempObj(tempString);
    delete[] tempString;
    return tempObj;
}

Mystring operator+=(Mystring& lhs, const Mystring& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

Mystring operator*(const Mystring& lhs, const int& rhs)
{
    char* tempString = new char[std::strlen(lhs.str) * rhs + 1];
    std::strcpy(tempString, lhs.str);
    for (size_t numIteration{ 0 }; numIteration < rhs - 1; ++numIteration)
    {
        std::strcat(tempString, lhs.str);
    }
    Mystring tempObj(tempString);
    delete[]tempString;
    return tempObj;
}

Mystring operator*=(Mystring& lhs, const int& rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

Mystring operator++(Mystring lhs)
{
    for (size_t i = 0; i < std::strlen(lhs.str); i++)
        lhs.str[i] = std::toupper(lhs.str[i]);
    return lhs;
}

Mystring operator++(Mystring& lhs, int)
{
    Mystring temp(lhs);
    operator++(lhs);
    return temp;
}