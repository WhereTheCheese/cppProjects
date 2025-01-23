#ifndef NODE_H
#define NODE_H
#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

/*

  This file contains all the function prototypes for the Node.cpp file. It creates the nodes, sets the value of the nodes, and then gets and sets the next node\
s.
  Author: Diya Shah
  Date: 11/15/2024

 */


class Node{
 public:
  //creates a new node setting the Student* as the value of the node
  Node(Student* newStudent);
  //destructor deletes the reference value of value and sets the next node to NULL
  ~Node();
  //this function sets the value of the node to student
  void setStudent (Student* newStudent);
  //returns the first name of the student (can be changed to return something else later in the assignment)
  char* getStudent();
  //set the next node giving it the new next value
  void setNext(Node* newnext);
  //get the next node to then get the different student values from that next node (creates the link)
  Node* getNext();

 private:
  //variables used in the functions
  Student* value;
  Node* next;


};

#endif

