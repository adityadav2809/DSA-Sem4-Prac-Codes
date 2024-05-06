/*Create  inorder threaded binary search tree and implement following operations
1. Insert a new node          2. Inorder and preorder traversal
3. Convert given binary search tree into threaded binary search  tree.
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    bool isthreaded;

    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
        isthreaded = false;
    }
};

void insert(Node*& root, int val) {
    Node* newNode = new Node(val);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    
    Node* curr = root;
    Node* parent = nullptr;

    // Find the position to insert the new node
    while (curr != nullptr) {
        parent = curr;
        if (val < curr->data) {
            if (curr->left == nullptr) {
                curr->left = newNode;
                newNode->right = curr;
                newNode->isthreaded = true;
                return;
            }
            curr = curr->left;
        } else {
            if (!curr->isthreaded) {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    return;
                }
                curr = curr->right;
            } else {
                newNode->right = curr->right;
                curr->right = newNode;
                curr->isthreaded = false;
                newNode->isthreaded = true;
                return;
            }
        }
    }
}


void inorder(Node* root){
    Node* curr = root;
    while(curr != nullptr){
        while(curr->left != nullptr){
            curr = curr->left;
        }
        cout<<curr->data<<" ";
        if (curr->isthreaded)
        {
            curr = curr->right;
        }
        else{
            curr = curr->right;
        }
    }
}

void preorder(Node* root){
    Node* curr = root;
    while(curr != nullptr){
        cout << curr->data << " ";
        if (curr->isthreaded)
        {
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
}

Node *createTBT(Node* root){
    if(root == nullptr) return nullptr;
    if(root->left == nullptr && root->right == nullptr) return root;
    if(root->left != nullptr){
        Node* l = createTBT(root->left);
        l->right = root;
        l->isthreaded = true;
    }
    if(root->right == nullptr) return root;
    return createTBT(root->right);
}

int main(){
    Node* root = nullptr;
    int choice, val;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert a new node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Convert the binary search tree to threaded binary search tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be inserted: ";
                cin >> val;
                insert(root, val);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                createTBT(root);
                cout << "Binary search tree has been converted to threaded binary search tree.\n";
                break;
            case 5:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
/*Sure, here's the algorithm for the operations described in the code with added comments:

1. **Insert a New Node**:
   - Start from the root and traverse the tree.
   - Compare the value of the node to be inserted with the current node's value.
   - If the value is greater, move to the right subtree; otherwise, move to the left subtree.
   - If a suitable position is found (where there's no right child or the right child is threaded), insert the new node there.

2. **Inorder Traversal**:
   - Start from the leftmost node of the tree.
   - Traverse the left subtree recursively until you reach a node with a null left child.
   - Print the value of the node.
   - If the node is threaded, move to its right child; otherwise, move to the right subtree and repeat the process.

3. **Convert the Binary Search Tree to Threaded Binary Search Tree (TBT)**:
   - Create a new TBT root node corresponding to the root of the original BST.
   - Traverse the BST in preorder.
   - For each node in the preorder traversal:
     - Recursively create a TBT node with the same value.
     - Connect the left child of the TBT node to the previously created node in the preorder traversal (if any).
     - Connect the right child of the TBT node to the next node in the preorder traversal.
   - Return the TBT root.

These operations allow for interactive manipulation and traversal of both a regular binary search tree and a threaded binary search tree.*/
