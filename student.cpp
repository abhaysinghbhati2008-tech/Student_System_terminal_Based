
#include "student.hpp"
#include <iostream>

Student::Student(int id, const std::string& name, double marks)
    : id(id), name(name), marks(marks) {}

int Student::getId() const {
    return id;
}

const std::string& Student::getName() const {
    return name;
}

double Student::getMarks() const {
    return marks;
}

void Student::display() const {
    std::cout << "ID: " << id
              << " | Name: " << name
              << " | Marks: " << marks << '\n';
}
