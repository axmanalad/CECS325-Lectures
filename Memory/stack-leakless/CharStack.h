//
// Created by neald on 3/15/2025.
//

#ifndef CHARSTACK_H
#define CHARSTACK_H
#include <cstddef>


class CharStack {

    // To make identifying constructors and destructors easier to track, we'll give every
    // CharStack a unique ID.
    int m_id;
    // and use a static counter to give incremental IDs to each stack that is created.
    static int m_nextId;

    char* m_data;
    size_t m_dataSize;
    size_t m_count {0};

public:
    CharStack();
    ~CharStack();
    CharStack(const CharStack& other);
    CharStack& operator=(const CharStack& rhs);


    void push(char c);
    char pop();
    size_t size() const;
    void clear();
};



#endif //CHARSTACK_H
