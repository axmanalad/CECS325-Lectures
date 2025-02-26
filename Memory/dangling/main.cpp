#include <iostream>
int& getIntRef() {
    int local = 100;
    return local;
}

int& getIntRef2() {
    int local = 200;
    return local;
}

void func1(int a[5]) {
    a[4] = 100;
}

int main() {
    std::cout << nullptr << std::endl;
    int y = 0;
    int x[2] = {0, 0};

    x[-1] = 100;
    std::cout << &y << " " << &x[0] << std::endl;
    std::cout << y << std::endl;

    return 0;
}