#include "palindromes.h"

bool isPalindrome(std::string s) {
    size_t i = 0;
    size_t j = s.size() - 1;

    while (i < j) {
        while (!isalpha(s[i])) {
            i++;
        }
        while (!isalpha(s[j])) {
            j--;
        }

        if (i >= j) {
            break;
        }

        if (s[i] != s[j]) {
            return false;
        }
        else {
            i++;
            j--;
        }
    }
    return true;
}