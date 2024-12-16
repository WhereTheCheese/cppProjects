#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

int main() {
    //Make the students
    Student* student1 = new Student(101);
    Student* student2 = new Student(102);

    //make nodes with those students
    Node* node1 = new Node(student1);
    Node* node2 = new Node(student2);

    //Link the nodes together
    node1->setNext(node2);

    //tests
    cout << "First student's ID: " << node1->getStudent()->id << endl;
    cout << "Second student's ID: " << node2->getStudent()->id << endl;
    
    Node* nextNode = node1->getNext();
    cout << "ID of the student in the next Node: " << nextNode->getStudent()->id << endl;

    //clean up
    delete node1;
    delete node2;

    return 0;
}
