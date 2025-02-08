#include "HashTable.h"
#include <iostream>
#include <iomanip>

HashTable::HashTable(int initialSize) : tableSize(initialSize), numStudents(0) {
    table = new Node*[tableSize]();
}
//its hash table time
HashTable::~HashTable() {
    for (int i = 0; i < tableSize; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* next = current->getNext();
            delete current;
            current = next;
        }
    }
    delete[] table;
}

int HashTable::hashFunction(int id) const {
    return id % tableSize;
}
//adjusts the size of the table when needed (kinda often)
void HashTable::resizeTable() {
    int newSize = tableSize * 2;
    Node** newTable = new Node*[newSize]();

    for (int i = 0; i < tableSize; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* next = current->getNext();
            Student* student = current->getStudent();
            int newIndex = hashFunction(student->getID());

            current->setNext(newTable[newIndex]);
            newTable[newIndex] = current;
            current = next;
        }
    }

    delete[] table;
    table = newTable;
    tableSize = newSize;
}
//add a student
void HashTable::addStudent(Student* student) {
    int id = student->getID();
    while (true) {
        int index = hashFunction(id);
        Node* current = table[index];
        int chainLength = 0;

        while (current != nullptr) {
            chainLength++;
            current = current->getNext();
        }

        if (chainLength < 3) {
            Node* newNode = new Node(student);
            newNode->setNext(table[index]);
            table[index] = newNode;
            numStudents++;
            break;
        } else {
            resizeTable();
        }
    }
}
//delete students
bool HashTable::deleteStudent(int id) {
    int index = hashFunction(id);
    Node* current = table[index];
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->getStudent()->getID() == id) {
            if (prev == nullptr) {
                table[index] = current->getNext();
            } else {
                prev->setNext(current->getNext());
            }
            delete current;
            numStudents--;
            return true;
        }
        prev = current;
        current = current->getNext();
    }
    return false;
}
//print out the students
void HashTable::printStudents() const {
    for (int i = 0; i < tableSize; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Student* student = current->getStudent();
            std::cout << student->getFirstName() << " " << student->getLastName()
                      << ", " << student->getID()
                      << ", " << std::fixed << std::setprecision(2) << student->getGPA() << std::endl;
            current = current->getNext();
        }
    }
}
//calcuates the avrages
double HashTable::calculateAverageGPA() const {
    double total = 0.0;
    int count = 0;

    for (int i = 0; i < tableSize; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            total += current->getStudent()->getGPA();
            count++;
            current = current->getNext();
        }
    }

    return (count == 0) ? 0.0 : (total / count);
}
