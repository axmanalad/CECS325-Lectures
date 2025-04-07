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

StringLinkedQueue::StringLinkedQueue(const StringLinkedQueue &other)
    : m_size{other.m_size}, m_id{++m_nextId} {
    std::cout << "Copy construct StringQueue " << m_id << " as a copy of " << other.m_id << std::endl;
    // Make a deep copy of other, by walking its list of Nodes, creating
    // a duplicate of each.
    Node *previous {nullptr};
    Node *p {other.m_head};
    for (size_t i {0}; i < other.m_size; ++i) {
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
}


StringLinkedQueue::StringLinkedQueue(StringLinkedQueue &&other) :
    // Take ownership of other's linked list.
    m_size{other.m_size}, m_head{other.m_head}, m_tail{other.m_tail},
    m_id{++m_nextId}
{
    std::cout << "Move construct StringQueue " << m_id << " from " << other.m_id << std::endl;

    // Set other's head and tail to null, so it won't delete them
    // when it is destroyed.
    other.m_head = other.m_tail = nullptr;
    other.m_size = 0;
}

StringLinkedQueue::~StringLinkedQueue() {
    std::cout << "Destroy StringQueue " << m_id << std::endl;
    // Delete all the Nodes in the list.
    Node *p {m_head};
    for (size_t i {0}; i < m_size; ++i) {
        Node *temp {p->m_next};

        // Deleting a Node also calls the destructor on the string it owns.
        delete p;

        // Move p to the next node in line.
        p = temp;
    }
}

StringLinkedQueue & StringLinkedQueue::operator=(const StringLinkedQueue &rhs) {
    std::cout << "Copy assign StringQueue" << m_id << " as a copy of " << rhs.m_id << std::endl;
    if (this == &rhs) {
        return *this;
    }

    // First destroy our existing Nodes, then deep copy rhs's.
    Node *p {m_head};
    for (size_t i {0}; i < m_size; ++i) {
        Node *temp {p->m_next};

        // Deleting a Node also calls the destructor on the string it owns.
        delete p;

        // Move p to the next node in line.
        p = temp;
    }
    Node *previous {nullptr};
    p = rhs.m_head;
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
    // Take over rhs after deleting our list.
    Node *p {m_head};
    for (size_t i {0}; i < m_size; ++i) {
        Node *temp {p->m_next};

        // Deleting a Node also calls the destructor on the string it owns.
        delete p;

        // Move p to the next node in line.
        p = temp;
    }

    m_head = rhs.m_head;
    m_tail = rhs.m_tail;
    m_size = rhs.m_size;
    rhs.m_head = nullptr;
    rhs.m_tail = nullptr;
    rhs.m_size = 0;

    return *this;
}

void StringLinkedQueue::enqueue(std::string value) {
    // REMINDER: if we intend to keep our own copy of a parameter, then we
    // should take that parameter as a full value, not as a reference or pointer.
    // Now the caller can decide if they want us to have a copy of their string
    // (passing it as a value), or if they want us to take over their temporary
    // string (using std::move to turn it into an rvalue).

    // Here is another use for dynamic memory: creating a value that will "outlive"
    // its scope. We want to store the given value in a Node, linking the node into
    // our list structure. But the Node that we create can't die when this function
    // terminates, so it must go into dynamic memory.

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

size_t StringLinkedQueue::size() const {
    return m_size;
}
