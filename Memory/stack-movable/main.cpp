#include <iostream>

#include "CharStack.h"

int main()
{
    CharStack s {};
    for (size_t i {0}; i < 10; ++i) {
        char input;
        std::cin >> input;
        s.push(input);
    }
}
