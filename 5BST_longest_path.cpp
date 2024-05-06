/*Beginning with empty binary search tree Construct BST by inserting the values in
given order. After construction a binary tree do:
1. Insert new node.
2. Find number of nodes from longest path from root.
3. Search a specific value and display comparisons required.
*/

#include <bits/stdc++.h>
using namespace std;

// Class to define a node in the binary search tree
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Function to insert a new node into the binary search tree
void insertnode(Node* &root, int val) {
    // If the tree is empty, create a new node as the root
    if (root == nullptr) {
        root = new Node(val);
        cout << "Node inserted successfully\n";
    }
    // If the value is greater than or equal to the current node's value, insert into the right subtree
    else if (val >= root->data) {
        insertnode(root->right, val);
    }
    // If the value is less than the current node's value, insert into the left subtree
    else {
        insertnode(root->left, val);
    }
}

// Function to calculate the height of the binary search tree
int height(Node* &root) {
    // Base case: If the tree is empty, return -1
    if (root == nullptr) {
        return -1;
    }
    // Recursively calculate the height of the left and right subtrees
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    // Return the maximum height of the left and right subtrees plus 1
    return max(leftheight, rightheight) + 1;
}

// Function to search for a specific value in the binary search tree
int search(Node *&root, int val, int comp) {
    // Base case: If the tree is empty or the value is not found, return -1
    if (root == nullptr) {
        return -1;
    }
    // If the value is found at the current node, return the number of comparisons made
    if (root->data == val) {
        return comp + 1;
    }
    // If the value is less than the current node's value, search in the left subtree
    if (val < root->data) {
        return search(root->left, val, comp + 1);
    }
    // If the value is greater than the current node's value, search in the right subtree
    else {
        return search(root->right, val, comp + 1);
    }
}

int main() {
    Node *root = nullptr;
    int choice, val;
    // Menu-driven interface for interacting with the binary search tree
    do {
        cout << "\nMENU\n";
        cout << "1 Insert node\n";
        cout << "2 Display tree height\n";
        cout << "3 Search a value\n";
        cout << "4 Exit\n";
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter value to insert : ";
                cin >> val;
                insertnode(root, val);
                break;
            }
            case 2: {
                cout << "Tree height : " << height(root);
                break;
            }
            case 3: {
                cout << "Enter a value to search : ";
                cin >> val;
                int s = search(root, val, 0);
                if (s != -1) {
                    cout << "Value found\n";
                    cout << "Comparisons : " << s << endl;
                }
                else {
                    cout << "Value not found" << endl;
                }
                break;
            }
            case 4: {
                cout << "Exiting-----" << endl;
                break;
            }
            default: {
                cout << "Enter valid choice : ";
            }
        }

    } while (choice != 4); // Continue until the user chooses to exit
    return 0;
}
/*Here's a concise algorithm for the provided C++ code:

### Insertion:
1. If the tree is empty, create a new node with the given value as the root.
2. If the value is greater than or equal to the current node's value, insert into the right subtree; otherwise, insert into the left subtree.
3. Repeat steps 1-2 recursively until a suitable position is found.

### Height Calculation:
1. Recursively calculate the height of the left and right subtrees.
2. Return the maximum height of the left and right subtrees plus 1.

### Search:
1. If the tree is empty or the value is not found, return -1.
2. If the value is found at the current node, return the number of comparisons made.
3. If the value is less than the current node's value, search in the left subtree; otherwise, search in the right subtree.

### Main Program:
1. Display a menu with options to insert a node, display the tree height, search for a value, or exit.
2. Based on the user's choice, execute the corresponding operation.
3. Repeat until the user chooses to exit.

This algorithm outlines the key operations of insertion, height calculation, search, and the main program flow for interacting with the binary search tree.*/
