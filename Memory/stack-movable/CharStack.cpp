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

CharStack::CharStack(const CharStack &other)
    : m_data{new char[other.m_dataSize]}, m_dataSize{other.m_dataSize}, m_count{other.m_count}
{
    // Perform a DEEP COPY of other's m_data array.
    for (size_t i = 0; i < m_count; ++i) {
        m_data[i] = other.m_data[i];
    }
}

CharStack::CharStack(CharStack &&other) noexcept
    : m_data{new char[other.m_dataSize]}, m_dataSize{other.m_dataSize}, m_count{other.m_count} {
    other.m_data = nullptr;
}

CharStack& CharStack::operator=(const CharStack &rhs) {
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

CharStack & CharStack::operator=(CharStack &&rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }

    delete[] m_data;
    m_data = rhs.m_data;
    m_count = rhs.m_count;
    m_dataSize = rhs.m_dataSize;

    rhs.m_data = nullptr;
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
            delete[] m_data;
        m_data = newData;
    }

    m_data[m_count] = c;
    ++m_count;
}

char CharStack::pop() {
    --m_count;
    return m_data[m_count];
}

size_t CharStack::size() const {
    return m_count;
}

void CharStack::clear() {
    m_count = 0;
}
