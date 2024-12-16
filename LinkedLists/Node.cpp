#include "Node.h"

//constructor, This sets up a new node with a studnt
Node::Node(Student* s) {
    student = s;
    next = nullptr; //start of list or end if last node
}


//Returns next node in list
Node* Node::getNext() {
    return next;
}

//Returns the Student that this Node holds
Student* Node::getStudent() {
    return student;
}

//changes locatioin Node points next
void Node::setNext(Node* newNext) {
    next = newNext;
}
