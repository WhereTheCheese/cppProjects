#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    char original[81];
    char cleaned[81];
    char reversed[81];
    char runAgain;

    do {
        int cleanedLength = 0;

        cout << "Enter a string to check if it's a palindrome:" << endl;
        cin.getline(original, 81);

        // Clean the input and store in new array
        for (int i = 0; original[i] != '\0'; i++) {
            if (isalnum(original[i])) {
                cleaned[cleanedLength] = tolower(original[i]);
                cleanedLength++;
            }
        }
        cleaned[cleanedLength] = '\0';  

        // Create reversed array
        for (int i = 0; i < cleanedLength; i++) {
            reversed[i] = cleaned[cleanedLength - 1 - i];
        }
        reversed[cleanedLength] = '\0';  

        // Compare cleaned and reversed arrays
        bool is_palindrome = (strcmp(cleaned, reversed) == 0);

        // Output the result
        if (is_palindrome) {
            cout << "The input is a palindrome." << endl;
        } else {
            cout << "The input is not a palindrome." << endl;
        }



        // Ask if they want to run again
        cout << "Do you want to check another string? (y/n): ";
        cin >> runAgain;
        cin.ignore(); 

    } while (tolower(runAgain) == 'y');

    cout << "Thank you for using the palindrome checker!" << endl;

    return 0;
}
