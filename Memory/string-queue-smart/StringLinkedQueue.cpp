//
// Created by neald on 4/7/2025.
//

#include "StringLinkedQueue.h"

#include <algorithm>
#include <stdexcept>


StringLinkedQueue::StringLinkedQueue(const StringLinkedQueue &other) {
    *this = other;
}

StringLinkedQueue::StringLinkedQueue(StringLinkedQueue &&other) {
    *this = std::move(other);
}

StringLinkedQueue & StringLinkedQueue::operator=(const StringLinkedQueue &rhs) {
    if (this == &rhs) {
        return *this;
    }

    clear();
    m_size = rhs.m_size;
    Node *previous {nullptr};
    // To talk through rhs, we just need to *borrow* a pointer to its Nodes.
    // We don't want to TAKE OWNERSHIP of them, so we don't use unique_ptr,
    // we just use a normal "raw" pointer.

    Node *p = rhs.m_head.get(); // get the raw pointer to the value m_head owns.
    for (size_t i {0}; i < rhs.m_size; ++i) {
        std::unique_ptr<Node> n {new Node{p->m_value, nullptr}};

        // Add n to follow the last Node we created.
        if (i == 0) {
            // This is the first Node, so it becomes the head.
            m_head = std::move(n);
            previous = m_head.get();
        }
        else {
            // Not the first node, so make it follow the previous node.
            previous->m_next = std::move(n);
            previous = previous->m_next.get();
        }
        p = p->m_next.get();
    }
    m_tail = previous;
    return *this;
}

StringLinkedQueue & StringLinkedQueue::operator=(StringLinkedQueue &&rhs) {
    if (this == &rhs) {
        return *this;
    }
    std::swap(m_head, rhs.m_head);
    std::swap(m_tail, rhs.m_tail);
    std::swap(m_size, rhs.m_size);
    return *this;
}

void StringLinkedQueue::enqueue(std::string value) {
    // Construct a new Node, and move the value into it.
    std::unique_ptr<Node> n {new Node{std::move(value), nullptr}};

    // If we are currently empty, then n becomes both head and tail.
    if (m_size == 0) {
        m_head = std::move(n);
        m_tail = m_head.get();
        m_size = 1;
    }
    else {
        // Otherwise, make the tail's next point to n, and then n becomes the tail.
        m_tail->m_next = std::move(n);
        m_tail = m_tail->m_next.get();
        ++m_size;
    }
}

std::string StringLinkedQueue::dequeue() {
    if (m_size == 0) {
        throw std::runtime_error("Cannot dequeue from an empty queue");
    }

    // Move the head value to a temporary string.
    std::string ret {std::move(m_head->m_value)};

    // By making m_head take over m_head's next, the old m_head will be destroyed.
    std::unique_ptr<Node> newHead {std::move(m_head->m_next)};
    // moving m_head->m_next into newHead sets m_head->m_next to null.
    // How newHead owns the "second" node and all the nodes that follow,
    // and m_head has nothing following it.

    // We just need m_head to take over newHead.
    m_head = std::move(newHead);
    --m_size;

    // If we are now empty, then m_tail has to be reset to null.
    if (m_size == 0) {
        m_tail = nullptr;
    }
    return ret;
}

void StringLinkedQueue::clear() {
    // Delete all the Nodes in the list.
    // This is stupidly easy.
    m_head = nullptr; // When nullptr is assigned to m_head, it will first delete the Node
                      // it currently owns. When that Node is deleted, it will destroy
                      // the m_next unique ptr that it owns, which will destroy the next
                      // Node in line.
    m_tail = nullptr;
    m_size = 0;
}

size_t StringLinkedQueue::size() const {
    return m_size;
}
