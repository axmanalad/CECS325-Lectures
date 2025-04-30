//
// Created by neald on 4/30/2025.
//

#ifndef SMARTPTR_H
#define SMARTPTR_H
#include <algorithm>

template <typename T>
class SmartPtr {
    T *m_value{nullptr};

public:
    SmartPtr() {}
    SmartPtr(T* value) : m_value{value} {}
    ~SmartPtr() {
        reset();
    }

    SmartPtr(const SmartPtr &other) = delete;
    SmartPtr& operator=(const SmartPtr& rhs) = delete;

    T* get() { return m_value; }
    T* operator->() { return get(); }
    void reset() {
        delete m_value;
        m_value = nullptr;
    }

    SmartPtr(SmartPtr &&other) {
        *this = std::move(other);
    }

    SmartPtr& operator=(SmartPtr &&rhs) {
        std::swap(m_value, rhs.m_value);
    }
};



#endif //SMARTPTR_H
