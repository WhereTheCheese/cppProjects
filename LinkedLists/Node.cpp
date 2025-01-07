#include "Node.h"

Node::Node(Student* s) {
    student = s;
    next = nullptr;
}

Node::~Node() {
    delete student;  // Clean up the student data

}

Node* Node::getNext() {
    return next;
}

Student* Node::getStudent() {
    return student;
}

void Node::setNext(Node* newNext) {
    next = newNext;
}
