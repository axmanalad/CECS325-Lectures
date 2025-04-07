//
// Created by neald on 4/7/2025.
//

#include "StringLinkedQueue.h"

#include <stdexcept>

int StringLinkedQueue::Node::m_nextId {0};
int StringLinkedQueue::m_nextId {100};

StringLinkedQueue::StringLinkedQueue() :m_id{++m_nextId} {
    std::cout << "Default construct StringQueue " << m_id << std::endl;
    // Nothing to do here, because an empty linked queue has no nodes,
    // unlike an empty array stack/queue that has reserve capacity.
}

StringLinkedQueue::StringLinkedQueue(const StringLinkedQueue &other) :
    m_id{++m_nextId} {
    std::cout << "Copy construct StringQueue " << m_id << " as a copy of " << other.m_id << std::endl;
    // Instead of duplicating the "walk the queue" logic, reuse the copy-assignment
    // operator we wrote below.
    *this = other;
    // Since the .h file already initialized m_head and m_tail to nullptr,
    // the copy-assignment operator won't have anything to delete before it moves
    // to deep copying the rhs.
}


StringLinkedQueue::StringLinkedQueue(StringLinkedQueue &&other) :
    m_id{++m_nextId}
{
    std::cout << "Move construct StringQueue " << m_id << " from " << other.m_id << std::endl;
    // Similar to the copy constructor, we'll just reuse the move-assignment operator.
    *this = std::move(other);
}

StringLinkedQueue::~StringLinkedQueue() {
    std::cout << "Destroy StringQueue " << m_id << std::endl;
    clear();
}

StringLinkedQueue & StringLinkedQueue::operator=(const StringLinkedQueue &rhs) {
    std::cout << "Copy assign StringQueue" << m_id << " as a copy of " << rhs.m_id << std::endl;
    if (this == &rhs) {
        return *this;
    }

    // First destroy our existing Nodes, then deep copy rhs's.
    clear();

    m_size = rhs.m_size;
    Node *previous {nullptr};
    Node *p = rhs.m_head;
    for (size_t i {0}; i < rhs.m_size; ++i) {
        Node *n {new Node{p->m_value, nullptr}};

        // Add n to follow the last Node we created.
        if (i == 0) {
            // This is the first Node, so it becomes the head.
            m_head = n;
        }
        else {
            // Not the first node, so make it follow the previous node.
            previous->m_next = n;
        }
        previous = n;
        p = p->m_next;
    }
    m_tail = previous;
    return *this;
}

StringLinkedQueue & StringLinkedQueue::operator=(StringLinkedQueue &&rhs) {
    std::cout << "Move assign StringQueue " << m_id << " from " << rhs.m_id << std::endl;
    if (this == &rhs) {
        return *this;
    }

    // Cute trick: swap pointers with rhs, so that when it is destroyed, it will
    // free the list that lhs currently owns. And now lhs owns rhs's old nodes.

    std::swap(m_head, rhs.m_head);
    std::swap(m_tail, rhs.m_tail);
    std::swap(m_size, rhs.m_size);
    return *this;
}

void StringLinkedQueue::enqueue(std::string value) {
    // Construct a new Node, and move the value into it.
    Node *n {new Node {std::move(value), nullptr}};

    // If we are currently empty, then n becomes both head and tail.
    if (m_size == 0) {
        m_head = m_tail = n;
        m_size = 1;
    }
    else {
        // Otherwise, make the tail's next point to n, and then n becomes the tail.
        m_tail->m_next = n;
        m_tail = n;
        ++m_size;
    }
}

std::string StringLinkedQueue::dequeue() {
    if (m_size == 0) {
        throw std::runtime_error("Cannot dequeue from an empty queue");
    }

    // Move the head value to a temporary string.
    std::string ret {std::move(m_head->m_value)};

    // Delete the old m_head, point m_head to the old next.
    Node *temp = m_head->m_next;
    delete m_head;
    m_head = temp;
    --m_size;

    // If we are now empty, then m_tail has to be reset to null.
    if (m_size == 0) {
        m_tail = nullptr;
    }

    return ret;
}

void StringLinkedQueue::clear() {
    // Delete all the Nodes in the list.
    Node *p {m_head};
    for (size_t i {0}; i < m_size; ++i) {
        Node *temp {p->m_next};

        // Deleting a Node also calls the destructor on the string it owns.
        delete p;

        // Move p to the next node in line.
        p = temp;
    }
    m_head = m_tail = nullptr;
    m_size = 0;
}

size_t StringLinkedQueue::size() const {
    return m_size;
}
