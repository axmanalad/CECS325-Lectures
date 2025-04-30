//
// Created by neald on 4/30/2025.
//

#ifndef CHARSTACK_H
#define CHARSTACK_H
#include <memory>


class CharStack {
    std::unique_ptr<char[]> m_data;
    size_t m_dataSize {8};
    size_t m_count {0};

public:
    CharStack();
    // The default destructor will run the destrutor of m_data,
    // which will delete the array that it owns.
    ~CharStack() = default;
    // We don't even need this line, to be honest.

    // Because unique_ptr can't be copied, our CharStack won't auto-generate
    // the implicit (shallow) copy constructor and copy assignment operator.
    // Leak avoided!

    // If we *want* CharStack to be deep copyable, we must write that ourselves.
    CharStack(const CharStack& other);
    CharStack &operator=(const CharStack &rhs);

    // If we *want* CharStack to be moveable, we must write that ourselves.
    CharStack(CharStack &&other);
    CharStack &operator=(CharStack &&rhs);


    void push(char c);
    char pop();
    size_t size() const;
    void clear();
};



#endif //CHARSTACK_H
