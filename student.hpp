
#pragma once

#include <string>

class Student {
private:
    int id;
    std::string name;
    double marks;

public:
    Student(int id, const std::string& name, double marks);

    int getId() const;
    const std::string& getName() const;
    double getMarks() const;

    void display() const;
};
