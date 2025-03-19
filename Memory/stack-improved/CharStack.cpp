//
// Created by neald on 3/15/2025.
//

#include "CharStack.h"

#include <stdexcept>

CharStack::CharStack()
    : m_data{new char[4]}, m_dataSize{4} {
}

CharStack::~CharStack() {
    delete[] m_data;
}

void CharStack::push(char c) {
    // If there are currently X elements in the stack, the new value
    // goes at index X, assuming there is room for it.
    // So we first make sure there is space.
    if (m_count == m_dataSize) {
        // We are already full. We must first create an array with enough space,
        // then copy over the old array, then add the new element.

        // Let's double the size of our array.
        char *newData{new char[m_dataSize * 2]};
        // Now copy the old array to the new one.
        for (size_t i = 0; i < m_dataSize; ++i) {
            newData[i] = m_data[i];
        }
        // Save the new data size.
        m_dataSize *= 2;

        delete[] m_data;
        m_data = newData;
        // Now continue, knowing we have enough space for the new element.
    }

    m_data[m_count] = c;
    ++m_count;

    // The *logic* of this function works, but what did we forget to do
    // as C++ programmers?
}

char CharStack::pop() {
    if (m_count > 0) {
        --m_count;
        return m_data[m_count];
    }
    else {
        throw std::runtime_error("Can't pop from empty stack");
    }
    // Notice how the top element isn't actually erased. But what happens
    // the next time we push a value?
}

size_t CharStack::size() const {
    return m_count;
}

void CharStack::clear() {
    m_count = 0;
    // Why does this clear the stack?
}
