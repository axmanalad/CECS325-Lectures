#include <iostream>

#include "CharStack.h"

CharStack makeStack() {
    CharStack temp{};
    for (size_t i {0}; i < 10; ++i) {
        temp.push('a');
    }
    // Temp is allocated in automatic storage. When makeStack returns,
    // what happens to temp and the data array it owns?
    // It is destroyed!

    // But we want to use the CharStack constructed here back in the main...
    // So how can that happen?



    // Normally, we would just return temp here. The std::move just exhibits
    // an OLDER behavior in C++ that is still worth knowing.
    return std::move(temp);
}

int main()
{
    // We fixed stacks leaking their array when they are destroyed.
    for (size_t i = 0; i < 10; ++i) {
        CharStack s {};
        // The CharStack destructor deletes the dynamic array owned by s.
        // No leaking!
    }

    std::string pattern;
    std::cout << "Stack loop done" << std::endl;
    std::cout << "Input a character to continue...";
    std::cin >> pattern;

    // A proper copy constructor fixes shallow copies sharing a data array,
    // leading to double deletion.
    CharStack s1 {};
    for (size_t i = 0; i < 10; ++i) {
        CharStack copy {s1};
        // Our proper copy-constructor does a *deep* copy of s1. "copy" has its
        // own dynamic array that has the same data as s1.
        // When copy goes out scope, its destructor destroys its own array.
    }

    std::cout << "Copy constructor loop done" << std::endl;
    std::cout << "Input a character to continue...";
    std::cin >> pattern;

    // A proper copy-assignment operator fixes shallow assignment sharing a data array,
    // and also failing to delete the LHS's existing array.
    for (size_t i = 0; i < 10; ++i) {
        CharStack s2 {}; // default constructor gives s2 a dynamic array.
        s2 = s1; // this is the COPY ASSIGNMENT operator.
        // To assign s2 a copy of s1, we first delete s2's data array, and then
        // do a deep-copy of s1's array.
    }

    // No more memory leaks!
    std::cout << "Copy assignment loop done" << std::endl;
    std::cout << "Input a character to continue...";
    std::cin >> pattern;


    // One last demo: what happens when an object is returned from a function?
    // makeStack will construct a stack, push 10 characters, and then return
    // that stack to us.
    CharStack r {makeStack()};
    std::cout << r.size() << std::endl;
    // Where is r in memory? Where is the stack that was constructed in
    // makeStack()? What is the relationship between r and the other stack?


    // A modern C++ compiler, with the std::move in makeStack(), will ELIDE
    // the "temp" variable completely, instead using "r" back in the main to store
    // the stack directly, so no copy has to be made.

    // Another example of copy elision:
    CharStack e {CharStack{}}; // default construct a CharStack, then copy that into e.
    // Is the temporary empty stack really necessary? No. So the compiler elides the copy,
    // instead directly constructing e with the default constructor.

    std::cout << "Program ending. Automatic storage will be cleared." << std::endl;
    return 0;
}
