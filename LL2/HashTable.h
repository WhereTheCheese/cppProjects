#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"
#include "Student.h"

class HashTable {
private:
    Node** table;
    int tableSize;
    int numStudents;

    int hashFunction(int id) const;
    void resizeTable();

public:
    HashTable(int initialSize = 100);
    ~HashTable();

    void addStudent(Student* student);
    bool deleteStudent(int id);
    void printStudents() const;
    double calculateAverageGPA() const;
};

#endif
