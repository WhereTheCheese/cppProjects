#include <iostream>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

void addStudent(Node*& head, Student* student);
void printStudents(Node* head);
Node* deleteStudent(Node* head, int id);
double calculateAverageGPA(Node* head, int count, double total);

//add a student to the list
void addStudent(Node*& head, Student* student) {
    if (!head || student->getID() < head->getStudent()->getID()) {
        Node* newNode = new Node(student);
        newNode->setNext(head);
        head = newNode;
        return;
    }

    Node* nextNode = head->getNext();
    addStudent(nextNode, student);
    head->setNext(nextNode);
}

//print all of the students names
void printStudents(Node* head) {
    if (!head) return;

    Student* student = head->getStudent();
    cout << student->getFirstName() << " " << student->getLastName()
         << ", " << student->getID()
         << ", " << fixed << setprecision(2) << student->getGPA() << endl;

    printStudents(head->getNext());
}

//delete students by their ID
Node* deleteStudent(Node* head, int id) {
    if (!head) return nullptr;

    if (head->getStudent()->getID() == id) {
        Node* temp = head->getNext();
        delete head;
        return temp;
    }

    head->setNext(deleteStudent(head->getNext(), id));
    return head;
}

//avrage the gpa of the students
double calculateAverageGPA(Node* head, int count, double total) {
    if (!head) return count == 0 ? 0.0 : total / count;

    double gpa = head->getStudent()->getGPA();
    return calculateAverageGPA(head->getNext(), count + 1, total + gpa);
}

int main() {
    Node* head = nullptr;
    string command;

    while (true) {
        cout << "Enter command (ADD, PRINT, DELETE, AVERAGE, QUIT): ";
        cin >> command;

        if (command == "ADD") {
            string firstName, lastName;
            int id;
            double gpa;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter GPA: ";
            cin >> gpa;

            Student* newStudent = new Student(firstName, lastName, id, gpa);
            addStudent(head, newStudent);
        } else if (command == "PRINT") {
            printStudents(head);
        } else if (command == "DELETE") {
            int id;
            cout << "Enter student ID to delete: ";
            cin >> id;
            head = deleteStudent(head, id);
        } else if (command == "AVERAGE") {
            double average = calculateAverageGPA(head, 0, 0.0);
            cout << "Average GPA: " << fixed << setprecision(2) << average << endl;
        } else if (command == "QUIT") {
            break;
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    //deal with memory stuff
    while (head) {
        Node* temp = head->getNext();
        delete head;
        head = temp;
    }

    return 0;
}
