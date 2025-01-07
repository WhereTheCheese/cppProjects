
#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

int main() {
    // Create student objects + Nodes for those students.
    Student* student1 = new Student(101);
    Student* student2 = new Student(102);

    Node* node1 = new Node(student1);
    Node* node2 = new Node(student2);

    //Link the nodes, can add more here for part 2 and make a linked list (insert mind blown emoji)
    node1->setNext(node2);

    //Test the functions
    cout << "First student's ID: " << node1->getStudent()->getId() << endl;
    cout << "Second student's ID: " << node2->getStudent()->getId() << endl;

    Node* nextNode = node1->getNext();
    cout << "ID of the student in the next Node: " << nextNode->getStudent()->getId() << endl;

    // Clean up
    delete node2;
    delete node1;

    return 0;
}
