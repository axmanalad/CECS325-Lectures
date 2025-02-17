#include <iostream>
#include "palindromes.h"
int main() {

    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    bool isPal = isPalindrome(input);
    if (isPal) {
        std::cout << "\"" << input << "\" is a palindrome." << std::endl;
    }
    else {
        std::cout << "\"" << input << "\" is not a palindrome." << std::endl;
    }
    return 0;
}
