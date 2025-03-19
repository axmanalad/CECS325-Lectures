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

    // Very similarly, when an existing object is ASSIGNED (operator=) another
    // value, C++ does a *member-wise* shallow copy.
    for (size_t i = 0; i < 10; ++i) {
        CharStack s2 {}; // default constructor gives s2 a dynamic array.
        s2 = s1; // this is the COPY ASSIGNMENT operator.

        // The implicit copy assignment operator does a member-wise copy
        // of rhs into lhs. This is DOUBLE TROUBLE:
        // 1. The pointer to lhs's m_data array is lost, leaking it.
        // 2. lhs.m_data will point to rhs.m_data, causing the double-delete problem
        //    from before.
    }

    return 0;
}
