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
            char open {brackets.pop()};
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
()
    std::cout << "Input a character to continue...";
    std::cin >> pattern;

    // Demonstrate a subtle MEMORY LEAK in the CharStack class.
    for (size_t i = 0; i < 1000000; ++i) {
        CharStack s {};
        // s allocates a char[4] in dynamic storage when constructed.
        // At the end of the loop, s is destroyed.
        // But what happens to the m_data array?
        // Watch the memory use of this program in Task Manager.
    }

    std::cout << "Stack loop done" << std::endl;
    std::cout << "Input a character to continue...";
    std::cin >> pattern;
}
