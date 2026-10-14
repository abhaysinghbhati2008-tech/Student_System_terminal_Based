
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "student.hpp"

using namespace std;

void addStudent(vector<Student>& students) {
    int id;
    string name;
    double marks;

    cout << "Enter student ID: ";
    cin >> id;

    for (const Student& student : students) {
        if (student.getId() == id) {
            cout << "Student ID already exists!\n";
            return;
        }
    }

    cout << "Enter student name: ";
    getline(cin >> ws, name);

    cout << "Enter marks: ";
    cin >> marks;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid marks input!\n";
        return;
    }

    if (marks < 0 || marks > 100) {
        cout << "Marks must be between 0 and 100.\n";
        return;
    }

    students.emplace_back(id, name, marks);
    cout << "Student added successfully!\n";
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    for (const Student& student : students) {
        student.display();
    }
}

void searchStudent(const vector<Student>& students) {
    int id;

    cout << "Enter student ID to search: ";
    cin >> id;

    for (const Student& student : students) {
        if (student.getId() == id) {
            student.display();
            return;
        }
    }

    cout << "Student not found.\n";
}

void calculateAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available to calculate average.\n";
        return;
    }

    double total = 0;

    for (const Student& student : students) {
        total += student.getMarks();
    }

    cout << "Class average: "
         << total / students.size() << '\n';
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== Student Manager =====\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Search student by ID\n";
        cout << "4. Calculate class average\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                searchStudent(students);
                break;

            case 4:
                calculateAverage(students);
                break;

            case 5:
                cout << "Exiting Student Manager.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
