//
// Created by neald on 3/15/2025.
//

#ifndef CHARSTACK_H
#define CHARSTACK_H
#include <cstddef>
class CharStack {
    char* m_data;
    size_t m_dataSize;
    size_t m_count {0};

public:
    CharStack();
    ~CharStack();

    void push(char c);
    char pop();
    size_t size() const;
    void clear();
};



#endif //CHARSTACK_H
