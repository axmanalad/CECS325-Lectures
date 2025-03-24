#include <iostream>
#include <cmath>
#include <string>
#include <bits/ranges_algo.h>

void lvRef(std::string &r) {
    r = "Hello!";
}

void clvRef(const std::string &r) {
    std::cout << r << std::endl;
}

void rvRef(std::string &&r) {
}



class StringStack {
    std::string *m_data;
    size_t m_count {0};
    size_t m_dataSize;

public:
    StringStack() : m_data{new std::string[4]}, m_dataSize{4} {}
    void push(const std::string& value) {
        if (m_count == m_dataSize) {
            // resize and copy the old data.
        }
        std::cout << "string&&" << std::endl;
        // Use the copy-assignment operator to assign a DEEP COPY
        // into the data array.
        m_data[m_count] = value;
    }

    void push(std::string&& value) {
        if (m_count == m_dataSize) {
            // resize and copy the old data.
        }

        // Use std::move to "take over" the temporary string.
        // The string class can construct a new string by taking over another
        // string, taking its data pointer without deep copying it.
        // Why is that ok? Because value is a temporary about to be destroyed.
        // If we take over its data pointer, it will have nothing to destroy.
        m_data[m_count] = std::move(value);
    }
};

int main() {
    // C++ distinguishes between lvalues and rvalues.
    // lvalue: a value that lives in an assigned memory address.
    // e.g., in static, automatic, or dynamic memory.
    // i.e., an lvalue can be on the LEFT (l) side of an assignment operator.
    int x{2};
    int y{5};
    std::string s{"Hello, world"};
    int a[5]{0, 1, 2, 3, 4};
    // x, y, and s are all lvalues. Each element of a is an lvalue.


    // rvalue: a value that can appear on the *right side* of an assignment.
    // e.g., lvalues, plus literals and temporaries.
    x = y; // r is activing as an rvalue.
    x = 10; // 10 is an rvalue.
    x = y + 5; // the temporary result of r+5 is an rvalue.
    double z{std::sqrt(x)}; // the temporary result of sqrt(x) is an rvalue.

    // When we learned reference types earlier this semester, we were actually
    // learning *lvalue references*.
    int &r = x;
    // When an lvalue reference is declared, it must be initialized with an lvalue.
    // It CANNOT be initialized with an rvalue.
    // These don't compile; why not?
    // int& r2 = 5;
    // int& r3 = y + x;

    // When a function takes an lvalue reference parameter, we must give it an lvalue
    // and not a literal or temporary.
    lvRef(s); // OK; s is an lvalue.
    // lvRef("Hello"); // Illegal; "Hello" is a string literal, an rvalue.
    // lvRef(s + "Goodbye"); // Illegal; s + "Goodbye" is a temporary string (rvalue).
    // Explain why this is true in your own words.


    // const lvalue references, on the other hand, CAN be assigned to rvalues.
    const std::string &c = s + "Goodbye";
    clvRef(s + s); // s + s is a temporary (rvalue), can be passed to const lvalue reference.

    // An rvalue reference is a reference that can only be assigned rvalues that are NOT
    // lvalues.
    std::string &&d {"Hello"}; // Allowed; "Hello" is a literal.
    std::string &&e {s + s}; // Allowed; s + s is a temporary.
    // std::string &&g {s}; // Not allowed; s is an lvalue.

    rvRef(s + s);
    rvRef("Hello");
    // rvRef(s); // Not allowed.

    StringStack st {};
    // Read and push 5 strings from the console.
    for (size_t i{0}; i < 5; ++i) {
        std::string temp;
        std::cin >> temp;

        // Push temp into the stack, but notice that we don't need it anymore.
        // We use std::move to identify that temp is not needed here anymore;
        // it is converted into an rvalue reference, and the StringStack
        // push(std::string&&) function is called.
        st.push(std::move(temp));
    }
}