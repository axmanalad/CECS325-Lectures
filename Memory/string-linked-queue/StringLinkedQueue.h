#ifndef STRINGLINKEDQUEUE_H
#define STRINGLINKEDQUEUE_H
#include <iostream>
#include <string>

class StringLinkedQueue {
struct Node {
    std::string m_value {};
    Node *m_next {nullptr};
    int m_id;
    static int m_nextId;

    Node(std::string value, Node* next)
        : m_value{std::move(value)},
          m_next{next},
          m_id{++m_nextId}
    {
        std::cout << "Consruct Node " << m_id << std::endl;
    }

    // This destructor is NOT NECESSARY, I just use it for debugging output.
    ~Node() {
        std::cout << "Destroy Node " << m_id << std::endl;
    }
};

    Node *m_head {nullptr};
    Node *m_tail {nullptr};
    size_t m_size {0};
    int m_id;
    static int m_nextId;

public:
    StringLinkedQueue();
    StringLinkedQueue(const StringLinkedQueue &other);
    StringLinkedQueue(StringLinkedQueue &&other);
    ~StringLinkedQueue();

    StringLinkedQueue& operator=(const StringLinkedQueue &rhs);
    StringLinkedQueue& operator=(StringLinkedQueue &&rhs);

    void enqueue(std::string value);
    std::string dequeue();
    size_t size() const;
};



#endif //STRINGLINKEDQUEUE_H
