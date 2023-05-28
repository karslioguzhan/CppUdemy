#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& in, Mystring& rhs);

private:
    char* str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                 // No-args constructor
    Mystring(const char* s);                                    // Overloaded constructor
    Mystring(const Mystring& source);                           // Copy constructor
    Mystring(Mystring&& source);                                // Move constructor
    ~Mystring();                                                // Destructor

    Mystring& operator=(const Mystring& rhs);                   // Copy assignment
    Mystring& operator=(Mystring&& rhs);                        // Move assignment

    void display() const;

    int get_length() const;                                      // getters
    const char* get_str() const;

    /*Overloading operator function definitions*/
    // Unary Minus operator
    Mystring operator-() const;
    // Equality operator
    bool operator==(const Mystring rhs) const;
    // Unequal operator
    bool operator!=(const Mystring rhs) const;
    // Less than operator
    bool operator<(const Mystring rhs) const;
    // Greater than operator
    bool operator>(const Mystring rhs) const;
    // Concatenation
    Mystring operator+(const Mystring& rhs) const;
    // Addition assignment operator
    Mystring& operator+=(const Mystring& rhs);
    // Multiplication operator (repeating)
    Mystring operator*(const int rhs) const;
    // Multiplication assignment operator
    Mystring& operator*=(const int rhs);
    // Pre Increment operator
    Mystring& operator++();
    // Post Increment operator
    Mystring operator++(int);

};

#endif // _MYSTRING_H_