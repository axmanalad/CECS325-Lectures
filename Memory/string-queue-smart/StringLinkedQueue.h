#ifndef STRINGLINKEDQUEUE_H
#define STRINGLINKEDQUEUE_H
#include <iostream>
#include <memory>
#include <string>

class StringLinkedQueue {
    struct Node {
        std::string m_value {};
        // Each Node *owns* the Node that follows it.
        std::unique_ptr<Node> m_next {nullptr};

        Node(std::string value, std::unique_ptr<Node> next)
            : m_value{std::move(value)},
              m_next{std::move(next)}
        {
        }

        // When a Node is destructed, it will automatically destruct all its fields,
        // which will destruct m_next, which will delete the Node that it points to.
    };

    // m_head *owns* the first Node in the list.
    std::unique_ptr<Node> m_head {nullptr};
    // m_tail merely *points to* the last Node, it does not *own* it.
    Node* m_tail {nullptr};
    size_t m_size {0};

public:
    StringLinkedQueue() = default;
    // The implicit default constructor is enough to initialize m_head and m_tail to null,
    // and m_size to 0.

    StringLinkedQueue(const StringLinkedQueue &other);
    StringLinkedQueue(StringLinkedQueue &&other);

    // What about the destructor?

    StringLinkedQueue& operator=(const StringLinkedQueue &rhs);
    StringLinkedQueue& operator=(StringLinkedQueue &&rhs);

    void enqueue(std::string value);
    std::string dequeue();
    void clear();
    size_t size() const;
};



#endif //STRINGLINKEDQUEUE_H
