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
        CharStack copy {s1};
        // Our proper copy-constructor does a *deep* copy of s1. "copy" has its
        // own dynamic array that has the same data as s1.
        // When copy goes out scope, its destructor destroys its own array.
    }

    // Similarly...
    for (size_t i = 0; i < 1000000; ++i) {
        CharStack s2 {}; // default constructor gives s2 a dynamic array.
        s2 = s1; // this is the COPY ASSIGNMENT operator.

        // By default, the copy assignment operator does a member-wise copy
        // of rhs into lhs. This is DOUBLE TROUBLE:
        // 1. The pointer to lhs's m_data array is lost, leaking it.
        // 2. lhs.m_data will point to rhs.m_data, causing the double-delete problem
        //    from before.
        // A proper copy-assignment operator fixes both of these; it deletes
        // any existing dynamic memory owned by the object, and then deep-copies
        // the rhs.
    }
    CharStack s2 {};
    s2 = s1;
             // copy assign destroys s2's existing array, then deep-copies s1's.



    return 0;
}
