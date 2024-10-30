#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//how to store student information
struct Student {
    char firstName[50];
    char lastName[50];
    int id;
    float GPA;
};

// Add student to the vector
void addStudent(vector<Student*> &students) {
    Student* newStudent = new Student;
    cout << "Enter first name: ";
    cin >> newStudent->firstName;
    cout << "Enter last name: ";
    cin >> newStudent->lastName;
    cout << "Enter ID: ";
    cin >> newStudent->id;
    cout << "Enter GPA: ";
    cin >> newStudent->GPA;
    students.push_back(newStudent);
}

// prints all students in the Vector
void printStudents(const vector<Student*> &students) {
    for (Student* student : students) {
        cout << student->firstName << " " << student->lastName << ", " << student->id << ", " << fixed << setprecision(2) << student->GPA << endl;
    }
}

// delet a student from the Vector by their ID
void deleteStudent(vector<Student*> &students, int idToDelete) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if ((*it)->id == idToDelete) {
            delete *it;
            students.erase(it);
            return;
        }
    }
    // error message
    cout << "Studnt not found." << endl;
}

int main() {
    vector<Student*> students;
    string command;

    while (true) {
        cout << "Enter command (ADD, PRINT, DELETE, QUIT): ";
        cin >> command;

        if (command == "ADD") {
            addStudent(students);
        } else if (command == "PRINT") {
            printStudents(students);
        } else if (command == "DELETE") {
            int idToDelete;
            cout << "Enter ID to delete: ";
            cin >> idToDelete;
            deleteStudent(students, idToDelete);
        } else if (command == "QUIT") {
            // Clean up memory before quitting
            for (Student* student : students) {
                delete student;
            }
            break;
        } else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
