#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Student; 

class Node {
private:
//makes the pointers
    Student* student; 
    Node* next;        

public:
    //makes a new node with student
    Node(Student* s);

    //cleans up node
    ~Node();

    //selecticts next node in chain
    Node* getNext();

    //selctios the student from current node
    Student* getStudent();

    //Points this node to next node
    void setNext(Node* newNext);
};

#endif // NODE_H
