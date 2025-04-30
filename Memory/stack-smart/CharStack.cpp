//
// Created by neald on 4/30/2025.
//

#include "CharStack.h"

#include <stdexcept>

CharStack::CharStack() : m_data{new char[m_dataSize]}
{
}

void CharStack::push(char c) {
    if (m_count == m_dataSize) {
        // We are already full. We must first create an array with enough space,
        // then copy over the old array, then add the new element.
        std::unique_ptr<char[]> newData {new char[m_dataSize * 2]};
        for (size_t i = 0; i < m_dataSize; ++i) {
            newData[i] = m_data[i];
        }
        m_dataSize *= 2;

        // When we move newData into m_data, the unique_ptr move assignment will
        // automatically delete what it already owns, before taking over the
        // memory of newData.
        m_data = std::move(newData);
    }

    m_data[m_count] = c;
    ++m_count;
}

CharStack::CharStack(const CharStack &other) : m_dataSize{other.m_dataSize}, m_count{other.m_count} {
    m_data = std::unique_ptr<char[]>{new char[m_dataSize]};
    for (size_t i {0}; i < m_count; ++i) {
        m_data[i] = other.m_data[i];
    }
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
    // Just like in push(), assigning m_data an r-value unique_ptr will cause it
    // to delete its old value before taking over the new one.
    m_data = std::unique_ptr<char[]>{new char[rhs.m_dataSize]};
    for (size_t i = 0; i < m_count; ++i) {
        m_data[i] = rhs.m_data[i];
    }
    return *this;
}

CharStack::CharStack(CharStack &&other) {
    *this = std::move(other);
}

CharStack & CharStack::operator=(CharStack &&rhs) {
    std::swap(m_data, rhs.m_data);
    std::swap(m_count, rhs.m_count);
    std::swap(m_dataSize, rhs.m_dataSize);
    return *this;
}

char CharStack::pop() {
    if (m_count > 0) {
        --m_count;
        return m_data[m_count];
    }
    else {
        throw std::out_of_range("Can't pop from empty stack");
    }
}

size_t CharStack::size() const {
    return m_count;
}

void CharStack::clear() {
    m_count = 0;
}