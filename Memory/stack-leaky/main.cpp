#include <iostream>
#include "CharStack.h"
int main()
{
    std::string pattern;
    std::cout << "Enter a bracket pattern: ";
    std::cin >> pattern;

    bool isBalanced {true};
    CharStack brackets {};
    for (char c : pattern) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (brackets.size() == 0) {
                isBalanced = false;
            }
            const char open {brackets.pop()};
            if (open == '(' && c != ')'
                || open == '[' && c != ']'
                || open == '{' && c != '}') {
                isBalanced = false;
                }
        }
        if (!isBalanced) {
            break;
        }
    }
    if (brackets.size() > 0) {
        isBalanced = false;
    }
    std::cout << "The string is " << (isBalanced ? "balanced" : "not balanced") << std::endl;

}
