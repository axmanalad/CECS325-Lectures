//
// Created by neald on 3/5/2025.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student {
    // Each instance of the Student class has its own set of these "member" fields...
    int m_id {};
    std::string m_firstName {};
    std::string m_lastName {};

    // Whereas *static* fields are SHARED between all instances of the class.
    static int m_nextStudentId; // This declares a static field, but we must initialize its
                                // value in the .cpp file.

public:
    Student() = default;
    Student(const std::string& firstName, const std::string& lastName);

    int getId() const;
    const std::string& getFirstName() const;
    // Other accessors and mutators (not important to this lesson)...

    // Because static fields aren't attached to an instance of the class, it makes
    // sense that you might retrieve them without using an instance of the class.
    // A *static function* is like a function that operates on the class as a whole,
    // rather than any individual instance of the class.
    // Static functions can use static fields of the class, but not the member fields.
    // (Why not?)
    static int getNextStudentId();

    // More practice with operators.
    bool operator<(const Student& rhs) const;
    bool operator==(const Student &rhs) const;
};

#endif //STUDENT_H
