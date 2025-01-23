#include "Node.h"
#include "Student.h" 


Node::Node(Student* newStudent) {
    value = newStudent;
    next = nullptr;
}

Node::~Node() {
    delete value; 
}

Student* Node::getStudent() {
    return value; 
}

void Node::setStudent(Student* newStudent) {
    value = newStudent;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* newNext) {
    next = newNext;
}













