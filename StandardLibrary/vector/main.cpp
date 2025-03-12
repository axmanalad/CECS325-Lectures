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
    for (int& d : digits) {
     //   std::cout << d << std::endl;
        d *= 2;
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


    // Removing elements.
    // pop_back(): removes the last element of the vector.
    // Reminder: at this point, digits = {8, 6, 7, 5, -3, -1, 9, 100}.
    digits.pop_back();
    // Now, digits = {8, 6, 7, 5, -3, -1, 9}.

    for (int i {0}; i < 2; ++i) {
        digits.pop_back();
    }
    // digits = {8, 6, 7, 5, -3}

    // To remove from an arbitrary position, we use erase().
    // erase(itr): removes the element pointed to by the given iterator.
    digits.erase(digits.begin());
    // Removes the 8.

    // To identify an arbitrary index, we can add an integer to the begin() iterator.
    digits.erase(digits.begin() + 2); // erases index 2.
    // digits = {6, 7, -3}


    // To insert at an arbitrary position, we use insert() simiarly to erase().
    // insert(itr, value): insert the value at the given iterator position, shifting
    // values at the existing position or after it to the right.
    digits.insert(digits.begin() + 1, 99); // insert 99 at index 1.
    // digits = {6, 99, 7, -3}
    digits.insert(digits.begin() + 3, 200);
    // digits = {6, 99, 7, 200, -3}.



    // FINAL LESSON:
    // Like *all other variables*, vectors are COPIED when assigned to another variable.
    std::vector<int> c {digits};
    // The vector copy constructor sets up c with its own array that copies each element
    // of digits.
    // Changes to c don't affect digits.
    c.pop_back();
    // digits still has 5 elements.

    // This is why we pass vectors by reference to functions; either const if we don't mutate,
    // or non-const if we do.
    return 0;
}


int findLargest(const std::vector<int>& values) {
    int largest { values[0] };
    for (auto itr {values.begin()}; itr != values.end(); ++itr) {
        if (*itr > largest) {
            largest = *itr;
        }
    }
    return largest;
}


bool isOrdered(const std::vector<int>& values) {
    for (size_t i = 0; i < values.size() - 1; ++i) {
        if (values[i] > values[i+1]) {
            return false;
        }
    }
    return true;
}

std::vector<int> reverseCopy(const std::vector<int>& values) {
    std::vector<int> temp {};

    for (auto itr = values.rbegin(); itr != values.rend(); ++itr) {
        temp.push_back(*itr);
    }
    return temp;
}