#include <iostream>

#include "CharStack.h"

int main()
{

    // Demonstrate a subtle MEMORY LEAK in the CharStack class.
    for (size_t i = 0; i < 1000000; ++i) {
        CharStack s {};
        // s allocates a char[4] in dynamic storage when constructed.
        // At the end of the loop, s is destroyed.
        // The CharStack destructor deletes the dynamic array owned by s.
        // No leaking!
    }

    std::string pattern;
    std::cout << "Stack loop done" << std::endl;
    std::cout << "Input a character to continue...";
    std::cin >> pattern;


    // Except we still have a different problem..
    CharStack s1 {};
    for (size_t i = 0; i < 1000000; ++i) {
        CharStack copy {s1}; // copy s1 to a new local variable.
        // copy is about to be destroyed. So what?
    }

    // When an object is constructed as a copy of another, C++ does a
    // *member-wise copy*. Every field in the new object gets the same
    // value as the object being copied, which means copy's m_data pointer
    // points to the same dynamic array as s1.
    // When copy goes out of scope, its destructor deletes the shared array.
    // The next copy to be destroyed will attempt to delete the shared array
    // again, which causes a run-time error.

    return 0;
}
