#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "HashTable.h"
#include "Student.h"

using namespace std;
//read in info from CSV files
vector<string> readCSV(const string& filename) {
    vector<string> lines;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return lines;
    }
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}

int main() {
    HashTable hashTable;
    string command;
    static int nextGeneratedID = 1;

    vector<string> firstNames = readCSV("first-names.csv");
    vector<string> lastNames = readCSV("last-names.csv");

    srand(time(nullptr));

    while (true) {
        cout << "Enter command (ADD, GENERATE, PRINT, DELETE, AVERAGE, QUIT): ";
        cin >> command;

        if (command == "ADD") {
            string firstName, lastName;
            int id;
            double gpa;

            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter GPA: ";
            cin >> gpa;

            Student* newStudent = new Student(firstName, lastName, id, gpa);
            hashTable.addStudent(newStudent);
        } else if (command == "GENERATE") {
            int count;
            cout << "Enter number of students to generate: ";
            cin >> count;

            if (firstNames.empty() || lastNames.empty()) {
                cout << "Error: Missing name data. Ensure CSV files are present." << endl;
                continue;
            }
    //adds the naems and stuff with the csv file
            for (int i = 0; i < count; ++i) {
                string firstName = firstNames[rand() % firstNames.size()];
                string lastName = lastNames[rand() % lastNames.size()];
                int id = nextGeneratedID++;
                double gpa = static_cast<double>(rand() % 401) / 100;

                Student* newStudent = new Student(firstName, lastName, id, gpa);
                hashTable.addStudent(newStudent);
            }
        } else if (command == "PRINT") {
            hashTable.printStudents();
        } else if (command == "DELETE") {
            int id;
            cout << "Enter student ID to delete: ";
            cin >> id;
            bool success = hashTable.deleteStudent(id);
            cout << (success ? "Deleted." : "Not found.") << endl;
        } else if (command == "AVERAGE") {
            double average = hashTable.calculateAverageGPA();
            cout << "Average GPA: " << fixed << setprecision(2) << average << endl;
        } else if (command == "QUIT") {
            break;
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
