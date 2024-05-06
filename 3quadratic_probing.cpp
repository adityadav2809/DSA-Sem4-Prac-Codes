/*Consider the student database of N students and their marks. Make use of a hash table
implementation to quickly insert and lookup students' PNR and marks.
Implement collision handling techniques:
1. linear probing
2. Implement collision handling using Quadratic probing
*/
#include <bits/stdc++.h> // This includes all standard libraries
using namespace std;

const int table_size = 10; // Define the size of the hash table

struct Student {
    int pnr; // Personal Identification Number
    int marks; // Student's marks
};

class Hashtable {
public:
    vector<pair<int, int>> table[table_size]; // Define a vector of pairs to represent the hash table

    int hashfunction(int pnr) { // Hash function to determine the index for a given PNR
        return pnr % table_size;
    }

    void insertlp(int pnr, int marks) { // Insertion using linear probing
        int index = hashfunction(pnr); // Compute the hash index
        while (!table[index].empty()) { // Probe linearly until an empty slot is found
            index = (index + 1) % table_size;
        }
        table[index].push_back({pnr, marks}); // Insert the student record
        cout << "Student inserted successfully" << endl;
    }

    void insertqp(int pnr, int marks) { // Insertion using quadratic probing
        int index = hashfunction(pnr); // Compute the hash index
        int originalindex = index;
        int i = 1;
        while (!table[index].empty()) { // Probe quadratically until an empty slot is found
            index = (originalindex + i * i) % table_size;
            i++;
        }
        table[index].push_back({pnr, marks}); // Insert the student record
        cout << "Student with PNR " << pnr << " inserted successfully'" << endl;
    }

    int search(int pnr) { // Search for a student record
        int index = hashfunction(pnr); // Compute the hash index
        while (!table[index].empty()) { // Linearly probe until an empty slot is found
            for (auto student : table[index]) { // Search for the student in the bucket
                if (student.first == pnr) {
                    cout << "Student record found" << endl;
                    return student.second; // Return the marks if found
                }
            }
            index = (index + 1) % table_size;
        }
        return -1; // Return -1 if student record not found
    }

    void display() { // Display the contents of the hash table
        for (int i = 0; i < table_size; i++) {
            cout << i;
            for (auto student : table[i]) { // Iterate through each bucket and its elements
                cout << " --> " << student.first << "(" << student.second << ")";
            }
            cout << endl;
        }
    }
};

int main() {
    Hashtable lp; // Create an instance of the Hashtable class
    int choice;
    int pnr;
    int marks;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert using Linear Probing\n";
        cout << "2. Insert using Quadratic Probing\n";
        cout << "3. Search for a student\n";
        cout << "4. Display the hash table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // User choice for menu options
        switch (choice) {
            case 1:
                cout << "Enter PNR of the student: ";
                cin >> pnr;
                cout << "Enter marks of the student: ";
                cin >> marks;
                lp.insertlp(pnr, marks); // Insert using linear probing
                break;
            case 2:
                cout << "Enter PNR of the student: ";
                cin >> pnr;
                cout << "Enter marks of the student: ";
                cin >> marks;
                lp.insertqp(pnr, marks); // Insert using quadratic probing
                break;
            case 3:
                cout << "Enter PNR of the student you want to search: ";
                cin >> pnr;
                marks = lp.search(pnr); // Search for a student
                if (marks != -1) {
                    cout << "Marks of student with PNR " << pnr << " is: " << marks << endl;
                } else {
                    cout << "Student with PNR " << pnr << " not found." << endl;
                }
                break;
            case 4:
                cout << "Hash Table: " << endl;
                lp.display(); // Display the hash table
                cout << endl;
                break;
            case 5:
                cout << "Exiting program...\n"; // Exit the program
                break;
            default:
                cout << "Invalid choice. Please try again.\n"; // Handle invalid input
        }
    } while (choice != 5);
    return 0;
}
/*Here's the algorithm for the provided C++ code implementing a hash table with linear probing and quadratic probing collision handling techniques:

Hash Table Insertion using Linear Probing:
Compute the hash index for the given PNR using a hash function.
If the computed hash index is already occupied, linearly probe to find the next available slot.
Insert the student's PNR and marks into the found empty slot in the hash table.
Hash Table Insertion using Quadratic Probing:
Compute the hash index for the given PNR using a hash function.
If the computed hash index is already occupied, use quadratic probing to find the next available slot.
Quadratically probe by incrementing the index by an increasing quadratic sequence (1, 4, 9, 16, ...) until an empty slot is found.
Insert the student's PNR and marks into the found empty slot in the hash table.
Search for a Student:
Compute the hash index for the given PNR using a hash function.
Linearly probe through the hash table starting from the computed hash index until an empty slot is encountered.
If the student's PNR is found during the probing process, return the corresponding marks.
If the end of the hash table is reached without finding the student's PNR, return -1 to indicate that the student record is not found.
Display Hash Table:
Iterate through each bucket (index) of the hash table.
For each bucket, display the student records (PNR and marks) stored in that bucket.
Menu Interface:
Display a menu with options for insertion using linear probing, insertion using quadratic probing, searching for a student, displaying the hash table, and exiting the program.
Prompt the user to enter their choice.
Based on the user's choice, execute the corresponding operation:
Insert data using linear or quadratic probing.
Search for a student's record.
Display the hash table.
Exit the program if the user chooses to do so.
Program Execution:
Create an instance of the hash table class.
Continuously prompt the user with the menu options until they choose to exit.
Execute the selected operation based on the user's choice.
*/
