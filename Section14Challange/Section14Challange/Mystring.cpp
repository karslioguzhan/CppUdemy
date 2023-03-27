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

/*Overloaded operators*/
Mystring Mystring::operator-() const
{
    char* tempString = new char[std::strlen(str)+1];
    std::strcpy(tempString, str);
    for (size_t numChar{ 0 }; numChar < std::strlen(str); ++numChar)
    {
        tempString[numChar] = std::tolower(str[numChar]);
    }
    Mystring tempObj{ tempString };
    delete[] tempString;
    return tempObj;
}

bool Mystring::operator==(const Mystring rhs) const
{
    return (std::strcmp(this->str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring rhs) const
{
    return (std::strcmp(this->str, rhs.str) != 0);
}

bool Mystring::operator<(const Mystring rhs) const
{
    return (std::strlen(this->str) < std::strlen(rhs.str));
}

bool Mystring::operator>(const Mystring rhs) const
{
    return (std::strlen(this->str) > std::strlen(rhs.str));
}

Mystring Mystring::operator+(const Mystring& rhs) const
{
    char* tempString = new char[std::strlen(this->str) + std::strlen(rhs.str) +1];
    std::strcpy(tempString, this->str);
    std::strcat(tempString, rhs.str);
    Mystring tempObj(tempString);
    delete[] tempString;
    return tempObj;
}

Mystring& Mystring::operator+=(const Mystring& rhs)
{
    *this = *this + rhs;
    return *this;
}

Mystring Mystring::operator*(const int rhs) const
{
    char* tempString = new char[std::strlen(this->str) * rhs + 1];
    std::strcpy(tempString, this->str);
    for (size_t numIteration{ 0 }; numIteration < rhs-1; ++numIteration)
    {
        std::strcat(tempString, this->str);
    }
    Mystring tempObj(tempString);
    delete[]tempString;
    return tempObj;
}
Mystring& Mystring::operator*=(const int rhs)
{
    *this = *this * rhs;
    return *this;
}

Mystring& Mystring::operator++()
{
    for (size_t i = 0; i < std::strlen(str); i++)
        str[i] = std::toupper(str[i]);
    return *this;
}

Mystring Mystring::operator++(int) 
{
    Mystring temp(*this);
    operator++();                    
    return temp;                     
}