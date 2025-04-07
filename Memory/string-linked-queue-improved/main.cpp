#include <iostream>
#include "StringLinkedQueue.h"
int main() {

    for (int i = 0; i < 1000; i++) {
        StringLinkedQueue q {};
        q.enqueue("Neal");
        q.enqueue("Jaclyn");
        q.enqueue("Ada");
        q.enqueue("Madison");

        if (true) {
            StringLinkedQueue q2 {q};
            std::cout << q2.dequeue() << std::endl;

            if (true) {
                StringLinkedQueue q3 {std::move(q2)};
                std::cout << "Using the moved queue" << std::endl;
            }
            std::cout << "q2 out of scope" << std::endl;
        }
    }

    std::cout << "Hi" << std::endl;
    char c;
    std::cin >> c;
}
