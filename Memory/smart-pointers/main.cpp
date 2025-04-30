#include <iostream>
#include "SmartPtr.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    SmartPtr<int> p {new int{10}};
    return 0;
}
