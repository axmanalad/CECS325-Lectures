#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

std::vector<int> randomVector() {
    std::random_device rd {};
    std::default_random_engine engine {rd()};
    std::uniform_int_distribution<int> range {1, 6000000};

    std::vector<int> r {};
    for (size_t i {0}; i < 1000000; ++i) {
        r.push_back(range(engine));
    }
    return r;
}

int main() {
    // This program generates two random vectors, sorts them, and prints them.

    // First, let's do it sequentially.
    std::cout << "Generating vector 1" << std::endl;
    std::vector<int> vec1 {randomVector()};
    std::cout << "Sorting vector 1" << std::endl;
    std::sort(vec1.begin(), vec1.end());

    std::cout << "Generating vector 2" << std::endl;
    std::vector<int> vec2 {randomVector()};
    std::cout << "Sorting vector 1" << std::endl;
    std::sort(vec2.begin(), vec2.end());

    std::cout << "Vector 1:" << std::endl;
    for (auto itr = vec1.begin(); itr < vec1.begin() + 100; ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Vector 2:" << std::endl;
    for (auto itr = vec2.begin(); itr < vec2.begin() + 100; ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
    return 0;
}
