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
    CharStack(const CharStack& other);
    CharStack(CharStack&& other) noexcept;

    CharStack& operator=(const CharStack& rhs);
    CharStack& operator=(CharStack&& rhs) noexcept;

    void push(char c);
    char pop();
    size_t size() const;
    void clear();
};



#endif //CHARSTACK_H
