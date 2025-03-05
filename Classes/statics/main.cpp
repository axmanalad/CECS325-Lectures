#include <iostream>
#include "Student.h"
int main() {
    Student s1 {"Neal", "Terrell"};
    Student s2 {"Steve", "Gold"};
    Student s3 {"Shannon", "Cleary"};

    std::cout << s1.getId() << std::endl;
    std::cout << s2.getId() << std::endl;
    std::cout << s3.getId() << std::endl;

    // Since getNextStudentId is static, we call it on the CLASS, not
    // on one of the objects.
    std::cout << Student::getNextStudentId() << std::endl;

    // Demonstrate operator< and operator==
    std::cout << (s1 < s2) << std::endl;
    std::cout << (s1 == s2) << std::endl;

    Student c {s1};
    std::cout << (s1 == c) << std::endl;

    return 0;
}
