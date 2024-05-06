/*Create binary tree/binary search tree with n nodes, do following operation
1. Insert a node         2. Delete a node from BST
3. All traversals (recursive and iterative)
*/

#include <bits/stdc++.h>
using namespace std;

// Class to define a node in the binary tree/binary search tree
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
void insertnode(Node *&root, int val) {
    // If the tree is empty, create a new node as the root
    if (root == nullptr) {
        root = new Node(val);
        cout << "Node inserted successfully\n";
    }
    // If the value is greater than or equal to the current node's value, insert into the right subtree
    else if (val >= root->data) insertnode(root->right, val);
    // If the value is less than the current node's value, insert into the left subtree
    else insertnode(root->left, val);
}

// Function to delete a node from the binary search tree
void deletenode(Node* &root, int val) {
    // Base case: If the tree is empty, return
    if (root == nullptr) return;
    // If the value is less than the current node's value, search in the left subtree
    if (val < root->data) deletenode(root->left, val);
    // If the value is greater than the current node's value, search in the right subtree
    else if (val > root->data) deletenode(root->right, val);
    // If the node with the value is found
    else {
        // Case 1: Node to be deleted has no child or only one child
        if (root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            root = temp;
        }
        // Case 2: Node to be deleted has two children
        else {
            Node *temp = root->right;
            // Find the minimum value node in the right subtree
            while (temp->left != nullptr) temp = temp->left;
            // Replace the value of the node to be deleted with the value of the minimum node
            root->data = temp->data;
            // Delete the minimum node from the right subtree
            deletenode(root->right, temp->data);
        }
    }
}

// Recursive function for inorder traversal of the binary tree
void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive function for preorder traversal of the binary tree
void preorder(Node *root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Recursive function for postorder traversal of the binary tree
void postorder(Node *root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Iterative function for preorder traversal of the binary tree
void preorderiter(Node *root) {
    if (root == nullptr) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if (temp->right != nullptr) st.push(temp->right);
        if (temp->left != nullptr) st.push(temp->left);
    }
}

// Iterative function for inorder traversal of the binary tree
void inorderiter(Node *root) {
    if (root == nullptr) return;
    stack<Node*> st;
    Node* temp = root;
    while (temp != nullptr || !st.empty()) {
        while (temp != nullptr) {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}

// Iterative function for postorder traversal of the binary tree
void postorderiter(Node *root) {
    if (root == nullptr) return;
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        Node* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->left != nullptr) st1.push(temp->left);
        if (temp->right != nullptr) st1.push(temp->right);
    }
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main() {
    Node *root = nullptr;
    int choice, val;
    // Menu-driven interface for interacting with the binary tree/binary search tree
    do {
        cout << "\nMENU\n";
        cout << "1 Insert node\n";
        cout << "2 Delete node\n";
        cout << "3 Inorder traversal\n";
        cout << "4 Preorder traversal\n";
        cout << "5 Postorder traversal\n";
        cout << "6 Preorder traversal (iterative)\n";
        cout << "7 Inorder traversal (iterative)\n";
        cout << "8 Postorder traversal (iterative)\n";
        cout << "9 Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter value to insert : ";
                cin >> val;
                insertnode(root, val);
                break;
            }
            case 2: {
                cout << "Enter value to delete: ";
                cin >> val;
                deletenode(root, val);
                cout << "Node deleted successfully\n";
                break;
            }
            case 3: {
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            }
            case 4: {
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            }
            case 5: {
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            }
            case 6: {
                cout << "Preorder Traversal: ";
                preorderiter(root);
                cout << endl;
                break;
            }
            case 7: {
                cout << "Inorder Traversal: ";
                inorderiter(root);
                cout << endl;
                break;
            }
            case 8: {
                cout << "Postorder Traversal: ";
                postorderiter(root);
                cout << endl;
                break;
            }
            case 9: {
                cout << "Exiting------" << endl;
                break;
            }
            default: {
                cout << "Enter valid choice : ";
            }
        }
    } while (choice != 9);
    return 0;
}
/*Sure, here's the algorithm of the provided code in short:

1. **Node Insertion**:
   - To insert a new node into the binary search tree:
     - If the tree is empty, create a new node as the root.
     - If the value is greater than or equal to the current node's value, insert into the right subtree; otherwise, insert into the left subtree.
     - Repeat this process recursively until a suitable position is found.

2. **Node Deletion**:
   - To delete a node from the binary search tree:
     - If the node is not found, return.
     - If the value is less than the current node's value, search in the left subtree.
     - If the value is greater than the current node's value, search in the right subtree.
     - If the node to be deleted has no child or only one child, replace it with its child.
     - If the node to be deleted has two children, replace its value with the minimum value in the right subtree, and recursively delete that minimum node.

3. **Tree Traversals**:
   - Inorder Traversal:
     - Recursively traverse the left subtree.
     - Visit the current node.
     - Recursively traverse the right subtree.
   - Preorder Traversal:
     - Visit the current node.
     - Recursively traverse the left subtree.
     - Recursively traverse the right subtree.
   - Postorder Traversal:
     - Recursively traverse the left subtree.
     - Recursively traverse the right subtree.
     - Visit the current node.
   - Iterative Traversals:
     - Use stacks to simulate the recursive traversal algorithms iteratively.

4. **Menu-Driven Interface**:
   - Display a menu with options to insert a node, delete a node, perform tree traversals (both recursive and iterative), and exit the program.
   - Based on the user's choice, execute the corresponding operation.

5. **Main Function**:
   - Initialize the root of the binary search tree to nullptr.
   - Continuously display the menu and perform the selected operation until the user chooses to exit.

This algorithm allows for the creation, manipulation, and traversal of a binary search tree using both recursive and iterative methods.*/
