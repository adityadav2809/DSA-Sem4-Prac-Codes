/*A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
Deleting keywords, updating values of any entry. Provide facility to display whole data sorted
in ascending/ Descending order. Also find how many maximum comparisons may require for finding
any keyword. Use Height balance tree (AVL) and find the complexity for finding a keyword*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    string keyword, meaning;
    Node *left = nullptr, *right = nullptr;
    int height = 1;
};

int height(Node* node) {
    return node ? node->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(string keyword, string meaning) {
    return new Node{keyword, meaning};
}

int getBalance(Node* N) {
    return N ? height(N->left) - height(N->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* node, string keyword, string meaning) {
    if (!node) return newNode(keyword, meaning);
    if (keyword < node->keyword)
        node->left = insert(node->left, keyword, meaning);
    else if (keyword > node->keyword)
        node->right = insert(node->right, keyword, meaning);
    else
        node->meaning = meaning;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && keyword < node->left->keyword) return rightRotate(node);
    if (balance < -1 && keyword > node->right->keyword) return leftRotate(node);
    if (balance > 1 && keyword > node->left->keyword) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && keyword < node->right->keyword) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, string keyword) {
    if (!root) return root;
    if (keyword < root->keyword)
        root->left = deleteNode(root->left, keyword);
    else if (keyword > root->keyword)
        root->right = deleteNode(root->right, keyword);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
    }
    if (!root) return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

string search(Node* root, string keyword, int& comparisons) {
    Node* current = root;
    while (current) {
        comparisons++;
        if (keyword == current->keyword) return current->meaning;
        else if (keyword < current->keyword) current = current->left;
        else current = current->right;
    }
    return "Keyword not found";
}

void traverseInOrder(Node* root) {
    if (root) {
        traverseInOrder(root->left);
        cout << root->keyword << ": " << root->meaning << endl;
        traverseInOrder(root->right);
    }
}

void traverseInOrderReverse(Node* root) {
    if (root) {
        traverseInOrderReverse(root->right);
        cout << root->keyword << ": " << root->meaning << endl;
        traverseInOrderReverse(root->left);
    }
}

int main() {
    Node* root = nullptr;
    int choice, comparisons;
    string keyword, meaning;
    do {
        cout << "\nAVL Dictionary\n1. Insert\n2. Delete\n3. Search\n4. Ascending\n5. Descending\n6. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Keyword to insert: "; cin >> keyword;
                cout << "Meaning: "; cin.ignore(); getline(cin, meaning);
                root = insert(root, keyword, meaning);
                break;
            case 2:
                cout << "Keyword to delete: "; cin >> keyword;
                root = deleteNode(root, keyword);
                break;
            case 3:
                cout << "Keyword to search: "; cin >> keyword; comparisons = 0;
                meaning = search(root, keyword, comparisons);
                cout << "Meaning: " << meaning << "\nComparisons: " << comparisons << endl;
                break;
            case 4: cout << "Ascending:\n"; traverseInOrder(root); break;
            case 5: cout << "Descending:\n"; traverseInOrderReverse(root); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}
/*Sure, here's a concise algorithm for the AVL Dictionary program:

1. **Node Definition**: Define a structure `Node` to represent each node in the AVL tree. Each node contains the keyword, meaning, pointers to left and right children, and height.

2. **Height Calculation**: Calculate the height of a node in the AVL tree.

3. **Rotation Functions**: Define functions for right and left rotations to balance the tree during insertion and deletion.

4. **Insertion**: Insert a new keyword and its meaning into the AVL tree while maintaining balance using rotations.

5. **Deletion**: Delete a keyword from the AVL tree while ensuring balance through rotations.

6. **Search**: Search for a keyword in the AVL tree, counting the number of comparisons made.

7. **Traversal**: Traverse the AVL tree in ascending and descending order, printing keywords and meanings.

8. **Main Function**: Implement a menu-driven loop in the `main()` function to allow users to insert, delete, search, and display the AVL tree.

That's the gist of the AVL Dictionary program algorithm. It efficiently manages operations while maintaining the AVL tree's balance.*/
