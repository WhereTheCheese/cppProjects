#include "Node.h"

/*
  This is the cpp file of Node.h. It deals with getting and setting the nodes correctly.
  Author: Diya Shah
  Date: 11/15/2024

*/


Node::Node(Student *newStudent){
  value=newStudent;
  next=NULL;
}
//destructor - deletes the char variables
Node::~Node(){
  delete &value;
  next=NULL;
}

//sets a student
void Node::setStudent(Student *newStudent){
  //sets value to the newstudent
  value=newStudent;
}

char* Node::getStudent(){
  //returns the first name of the value
  //can be changed based on value
  return value->getFirstName();
}

void Node::setNext(Node* newnext){
  //sets the next node
  next=newnext;
}

Node*Node::getNext(){
  //return the next node
  return next;
}
