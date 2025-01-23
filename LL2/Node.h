#ifndef NODE_H
#define NODE_H

/*

  This file contains all the function prototypes for the Node.cpp file. It creates the nodes, sets the value of the nodes, and then gets and sets the next node\
s.
  Author: Diya Shah and Andrew Washburn
  Date: 11/15/2024

 */

class Student;

class Node {
private:
    Student* value; 
    Node* next;     

public:
    Node(Student* newStudent);

    ~Node();

    Student* getStudent();    
    void setStudent(Student* newStudent);

    Node* getNext();
    void setNext(Node* newNext);
};

#endif



