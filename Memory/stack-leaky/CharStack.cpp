//
// Created by neald on 3/15/2025.
//

#include "CharStack.h"

#include <stdexcept>

CharStack::CharStack()
    : m_data{new char[4]{}}, m_dataSize{4} {
}

void CharStack::push(char c) {
    if (m_count == m_dataSize) {
        // Let's double the size of our array.
        char *newData{new char[m_dataSize * 2]};
        for (size_t i = 0; i < m_dataSize; ++i) {
            newData[i] = m_data[i];
        }
        m_dataSize *= 2;

        // Free the old m_data, and use newData from now on.
        delete[] m_data;
        m_data = newData;
    }

    m_data[m_count] = c;
    ++m_count;
}

char CharStack::pop() {
    // We can only pop if count > 0.
    if (m_count > 0) {
        --m_count;
        return m_data[m_count];
    }
    else {
        throw std::runtime_error("Can't pop an empty stack");
    }
}

size_t CharStack::size() const {
    return m_count;
}

void CharStack::clear() {
    m_count = 0;
}
