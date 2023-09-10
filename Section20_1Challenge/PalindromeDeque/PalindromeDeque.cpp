#include <iostream>
#include <cctype>
#include <deque>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque <char> compareDeque(s.begin(), s.end());

    // uppercase all characters
    std::transform(compareDeque.begin(), compareDeque.end(), compareDeque.begin(), ::toupper);
    
    // Delete all non alphabetic elements
    compareDeque.erase(std::remove_if(compareDeque.begin(), compareDeque.end(),
        [](char actualChar)
        {
            return !(std::isalpha(actualChar));
        }), compareDeque.end());

    // Copy and reverse Deque
    std::deque reverseCompare{ compareDeque };
    std::reverse(reverseCompare.begin(), reverseCompare.end());

    // Compare and return
    return std::equal(compareDeque.begin(), compareDeque.end(), reverseCompare.begin(), reverseCompare.end());
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
