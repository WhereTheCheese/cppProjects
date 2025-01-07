#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    int studentId;

public:
    //Constructor
    Student(int id);

    //Getter for id (since it's private)
    int getId() const;
};

#endif // STUDENT_H
