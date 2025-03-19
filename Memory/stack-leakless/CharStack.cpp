//
// Created by neald on 3/15/2025.
//

#include "CharStack.h"

#include <iostream>
#include <stdexcept>

int CharStack::m_nextId {0};

CharStack::CharStack()
    : m_id{++m_nextId}, m_data{new char[4]}, m_dataSize{4} {
    std::cout << "Default construct stack " << m_id << std::endl;
}

CharStack::~CharStack() {
    std::cout << "Destruct stack " << m_id << std::endl;
    delete[] m_data;
}

CharStack::CharStack(const CharStack &other)
    : m_id{++m_nextId}, m_data{new char[other.m_dataSize]}, m_dataSize{other.m_dataSize},
      m_count{other.m_count}
{
    std::cout << "Construct stack " << m_id << " as a copy of stack " << other.m_id << std::endl;
    // Perform a DEEP COPY of other's m_data array.
    for (size_t i = 0; i < m_count; ++i) {
        m_data[i] = other.m_data[i];
    }
}

CharStack& CharStack::operator=(const CharStack &rhs) {
    std::cout << "Override stack " << m_id << " as a copy of stack " << rhs.m_id << std::endl;
    // In a copy assignment operator, LHS *already exists* and has an existing
    // m_data array that must be destroyed, before deep copying rhs.
    // We first make sure that we aren't copy-assigning to OURSELF.
    if (this == &rhs) {
        return *this;
    }

    m_count = rhs.m_count;
    m_dataSize = rhs.m_dataSize;
    delete[] m_data;
    m_data = new char[rhs.m_dataSize];
    for (size_t i = 0; i < m_count; ++i) {
        m_data[i] = rhs.m_data[i];
    }
    return *this;
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
