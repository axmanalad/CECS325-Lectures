#include <iostream>
#include <vector>

int main() {
    // In C++, a "vector" is a list that uses an array to store its elements.
    std::vector<int> numbers {};
    // This vector can ony store integers. You must choose a type when creating the vector;
    // they are *homogenous*, just like arrays.
    // The default-constructed vector has no elements/values.

    // We can initialize the vector with a set of values.
    std::vector<int> digits {8, 6, 7, 5, 3, 0, 9};

    // Draw these vectors in memory.



    // .size() tells us the # of values in the vector.
    std::cout << digits.size() << std::endl;

    // Values can be appended to the end with push_back().
    digits.push_back(100);
    // Show how this changes digits in memory.



    // We can use [] or .at() to retrieve *references* to values.
    std::cout << digits[4] << std::endl;
    std::cout << digits.at(4) << std::endl;
    // What's the difference?

    // Because we get a reference back, we can mutate values in the vector
    // by assigning to the result of [] or .at()
    digits[5] = -1;
    digits.at(4) = -3;


    // We can iterate through vectors in three ways.

    // 1. For loop w/ indexes.
    for (size_t i {0}; i < digits.size(); ++i) {
        std::cout << digits[i] << std::endl;
    }

    // 2. Range-based for loop.
    for (int d : digits) {
        std::cout << d << std::endl;
    }
    // BE CAREFUL HERE: d is a *copy* of each integer in the vector.

    // 3. Using iterators.

    std::vector<int>::iterator itr {digits.begin()};
    while (itr != digits.end()) {
        // itr is an "iterator": an object that *points to* an element in a collection,
        // and can be "advanced" to the next object.
        std::cout << *itr << std::endl;
        // operator* "follows" the iterator to the value it's currently pointing at.

        // To go to the next element, we ++ the iterator.
        ++itr;
    }

    // This can be simplified using a for loop:
    for (std::vector<int>::iterator itr {digits.begin()}; itr != digits.end(); ++itr) {
        std::cout << *itr << std::endl;
    }

    // Even better, using "auto" to deduce the type of "itr".
    for (auto itr {digits.begin()}; itr != digits.end(); ++itr) {
        std::cout << *itr << std::endl;
    }

    // Even better, using std::begin and std::end, which also works on arrays.
    for (auto itr {std::begin(digits)}; itr != std::end(digits); ++itr) {
        std::cout << *itr << std::endl;
    }



    return 0;
}
