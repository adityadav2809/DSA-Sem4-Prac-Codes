/*Create inorder threaded binary search tree and implement following operations
1. Insert a new node  2. Inorder and preorder traversal
3. Convert given binary search tree into threaded binary search  tree.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool isthreaded;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        isthreaded = false;
    }
};

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

void insertbst(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }
    if (val >= root->data) {
        insertbst(root->right, val);
    }
    else {
        insertbst(root->left, val);
    }
}

void insert(Node*& root, int val) {
    Node* newNode = new Node(val);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node* curr = root;
    while (true) {
        if (val < curr->data) {
            if (curr->left == nullptr) {
                curr->left = newNode;
                newNode->right = curr;
                newNode->isthreaded = true;
                return;
            }
            curr = curr->left;
        }
        else {
            if (!curr->isthreaded || val < curr->right->data) {
                if (curr->right == nullptr || curr->right->isthreaded) {
                    newNode->right = curr->right;
                    curr->right = newNode;
                    curr->isthreaded = false;
                    newNode->isthreaded = true;
                    return;
                }
                curr = curr->right;
            }
            else {
                newNode->right = curr->right;
                curr->right = newNode;
                curr->isthreaded = false;
                newNode->isthreaded = true;
                return;
            }
        }
    }
}

void inorder(Node* root) {
    Node* curr = root;
    while (curr != nullptr) {
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        cout << curr->data << " ";
        if (curr->isthreaded) {
            curr = curr->right;
            if (curr == nullptr)
                break;
        }
        else {
            curr = curr->right;
            if (curr != nullptr)
                cout << curr->data << " ";
        }
    }
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    if (!root->isthreaded) preorder(root->left);
    preorder(root->right);
}

Node* createTBT(TreeNode* root1) {
    if (root1 == nullptr)
        return nullptr;
    Node* root = new Node(root1->data);
    if (root1->left != nullptr) {
        Node* l = createTBT(root1->left);
        l->right = root;
        l->isthreaded = true;
    }
    if (root1->right != nullptr) {
        root->right = createTBT(root1->right);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    TreeNode* root1 = nullptr;
    int choice, val, nodes;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert a new node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Convert the binary search tree to threaded binary search tree\n";
        cout << "4. Exit\n";
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
            cout << "Enter no. of nodes: ";
            cin >> nodes;
            cout << "Enter nodes for BST: ";
            for (int i = 0; i < nodes; i++) {
                cin >> val;
                insertbst(root1, val);
            }
            root = createTBT(root1);
            cout << "Binary search tree has been converted to threaded binary search tree.\n";
            cout << "Preorder Traversal : ";
            preorder(root);
            break;
        case 4:
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

