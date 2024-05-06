/*The dictionary file consists of a list of more than 100 correctly spelt lowercase words,
separated by whitespace. The words are inserted into the hash table. Handle collision
using separate chaining. After the reading of the dictionary file is complete, the program
prompts the user for input. After input is obtained, each word that the user enters into the
program is looked up within the hash table to see if it exists. If the entered word
exists within the hash table, then that word is spelt correctly. */

#include <bits/stdc++.h>
using namespace std;

const int SIZE = 26; // Size of the hash table

// Hash function to map a string to an index in the hash table
int hashfunction(const string &key) {
    char firstchar = key[0]; // Get the first character of the word
    if (firstchar >= 'a' && firstchar <= 'z') // Ensure it is a lowercase letter
        return (firstchar - 'a'); // Map 'a' to 0, 'b' to 1, ..., 'z' to 25
    return -1; // Invalid word
}

// Function to insert a word into the hash table
void insert(vector<vector<pair<string, bool>>> &table, string &key) {
    int index = hashfunction(key); // Compute the hash index
    if (index != -1)
        table[index].push_back({key, true}); // Insert the word into the appropriate bucket
    else
        cout << "invalid word " << key << endl; // Display error for invalid word
}

// Function to search for a word in the hash table
bool search(vector<vector<pair<string, bool>>> &table, string &key) {
    int index = hashfunction(key); // Compute the hash index
    if (index != -1) {
        for (auto it : table[index]) { // Search through the bucket
            if (it.first == key) {
                return true; // Word found
            }
        }
    }
    return false; // Word not found
}

// Function to display the contents of the hash table
void display(vector<vector<pair<string, bool>>> &table) {
    for (int i = 0; i < SIZE; i++) {
        cout << "Bucket " << static_cast<char>(i + 'a') << " : "; // Display the bucket label
        for (auto it : table[i]) { // Display words in the bucket
            cout << it.first << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<pair<string, bool>>> table(SIZE); // Initialize the hash table
    ifstream file("dict.txt"); // Open the dictionary file
    if (!file) {
        cerr << "error opening file" << endl; // Display error if file cannot be opened
    }
    string word;
    // Read words from the dictionary file and insert into the hash table
    while (file >> word) {
        insert(table, word);
    }
    int choice;
    string userInput;
    // Menu-driven interface to check spelling, display hash table, or exit
    do {
        cout << "\nMenu:\n";
        cout << "1. Check Spelling\n";
        cout << "2. Display Hash Table\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter word to check spelling: ";
                cin >> userInput;
                // Check if the entered word exists in the hash table
                if (search(table, userInput)) {
                    cout << "Correct spelling.\n";
                } else {
                    cout << "Incorrect spelling.\n";
                }
                break;
            case 2:
                // Display the hash table
                cout << "Hash Table:\n";
                display(table);
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 3); // Continue until the user chooses to exit
    return 0;
}
/*Here's a brief algorithm for the provided C++ code:

1. **Initialization**:
   - Define the size of the hash table.
   - Create a 2D vector to represent the hash table.

2. **Hash Function**:
   - Map the first character of each word to an index in the hash table.

3. **Insertion**:
   - Compute the hash index for the word.
   - Insert the word into the appropriate bucket of the hash table.

4. **Search**:
   - Compute the hash index for the word to be checked.
   - Search through the bucket for the word.
   - Return `true` if the word is found, indicating correct spelling; otherwise, return `false`.

5. **Display Hash Table**:
   - Iterate through each bucket of the hash table and display the words stored in it.

6. **Main Program**:
   - Open the dictionary file and read each word.
   - Insert each word into the hash table.
   - Display a menu with options for checking spelling, displaying the hash table, or exiting.
   - Based on the user's choice, execute the corresponding operation.
   - Repeat until the user chooses to exit.

This algorithm outlines the key steps of initializing, inserting, searching, and displaying words in the hash table, as well as the main program flow.*/
