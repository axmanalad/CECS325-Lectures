#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>
#include <random>

void randomizeVector(std::vector<int> *vec, int start, int end) {
    std::random_device rd {};
    std::default_random_engine engine {rd()};
    std::uniform_int_distribution<int> range {start, end};

    for (size_t i {0}; i < 1000000; ++i) {
        vec->push_back(range(engine));
    }
}

void generateAndSort(std::vector<int> *vec, int vectorNumber, int startValue, int endValue) {
    std::cout << "Generating vector " << vectorNumber << std::endl;
    randomizeVector(vec, startValue, endValue);
    std::cout << "Sorting vector " << vectorNumber << std::endl;
    std::sort(vec->begin(), vec->end());
}

int main() {
    // This program generates two random vectors, sorts them, and prints them.

    // To fix the printing race condition, we need to wait for both threads to
    // finish sorting; and then have just one thread (the main thread) print out
    // the sorted vectors, one at a time.

    // So we need t2 to be able to "return" its sorted vector back to the main thread.
    // But threads can't return data, and any values they put in automatic storage
    // are destroyed when the thread terminates.
    // So if a thread wants to "share memory" with another thread, it must do so
    // through dynamic storage.

    // Create  vector in dynamic storage; pass a pointer to it to the new thread.
    std::vector<int> *v1 {new std::vector<int>{}};
    std::thread t2 {generateAndSort, v1, 1, 1, 500000};

    // generatePrintAndSort now runs on a second thread, and sorts a vector that is stored
    // in dynamic storage.

    // The main thread can create its vector in automatic storage, since this is the thread
    // that will do the printing in the end.
    std::vector<int> v2 {};
    generateAndSort(&v2, 2, 500001, 9000000);

    // We'll get to this point once the main thread is done sorting. The join makes us wait
    // even more, if necessary, until the second thread is done sorting.
    t2.join();

    // Now print the vectors in sequence.
    std::cout << "Vector 1:" << std::endl;
    for (auto itr = v1->begin(); itr < v1->begin() + 100; ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl << std::endl;


    std::cout << "Vector 2:" << std::endl;
    for (auto itr = v2.begin(); itr < v2.begin() + 100; ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl << std::endl;

    return 0;
}
