#ifndef NODE_H
#define NODE_H

#include "Student.h"

class Node {
private:
    Student* student;  //Pointer to student data
    Node* next;       //Pointer to next node

public:
    //Creates node with student data
    Node(Student* s);

    //Cleans up the node and student data
    ~Node();

    //Returns pointer to next node in list
    Node* getNext();

    //Returns pointer to student data
    Student* getStudent();

    //Sets the next node pointer
    void setNext(Node* newNext);
};

#endif // NODE_H

