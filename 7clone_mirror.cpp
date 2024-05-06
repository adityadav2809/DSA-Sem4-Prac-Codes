/*Create binary tree/binary search tree with n nodes, do following operation
1. Insert a node        2. Find the height of a tree.
3. Create clone of a tree and then erase all nodes in a original tree.
4. create a Mirror image of a tree.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

void insertNode(Node *&root, int val)
{
    if (root == nullptr)
    {
        root = new Node(val);
        cout << "Node inserted successfully\n";
    }
    else if (val >= root->data)
        insertNode(root->right, val);
    else
        insertNode(root->left, val);
}

int height(Node *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

Node *clone(Node *root)
{
    if (root == nullptr)
        return root;
    Node *newNode = new Node(root->data);
    newNode->left = clone(root->left);
    newNode->right = clone(root->right);
    return newNode;
}

Node *mirrorImage(Node *root)
{
    if (root == nullptr)
        return nullptr;
    Node *temp = root->left;
    root->left = mirrorImage(root->right);
    root->right = mirrorImage(temp);
    return root;
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;
    int choice, val;
    do
    {
        cout << "\nMENU\n";
        cout << "1. Insert node\n";
        cout << "2. Display tree height\n";
        cout << "3. Clone tree\n";
        cout << "4. Create mirror image\n";
        cout << "5. Exit\n";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter value to insert: ";
            cin >> val;
            insertNode(root, val);
            break;
        }
        case 2:
        {
            cout << "Tree height: " << height(root) << endl;
            break;
        }
        case 3:
        {
            Node *clonedRoot = clone(root);
            cout << "Cloned tree: ";
            inorder(clonedRoot);
            cout << endl;
            break;
        }
        case 4:
        {
            Node *mirrorRoot = mirrorImage(root);
            cout << "Mirror image created." << endl;
            cout << "In-order traversal of mirror image: ";
            inorder(mirrorRoot);
            cout << endl;
            break;
        }
        case 5:
        {
            cout << "Exiting...";
            break;
        }
        default:
        {
            cout << "Enter valid choice." << endl;
            break;
        }
        }
    } while (choice != 5);
    return 0;
}
/*1. **Insert a Node (insertNode):**
   - Start from the root node.
   - If the tree is empty, create a new node with the given value and make it the root.
   - Otherwise, compare the value with the current node's value.
   - If the value is greater than or equal to the current node's value, recursively insert it into the right subtree.
   - If the value is less than the current node's value, recursively insert it into the left subtree.

2. **Find the Height of a Tree (height):**
   - If the tree is empty (root is null), return -1.
   - Recursively calculate the height of the left and right subtrees.
   - Return the maximum height among the left and right subtrees, incremented by 1.

3. **Clone a Tree (clone):**
   - If the root is null, return null.
   - Create a new node with the same value as the current node.
   - Recursively clone the left and right subtrees.
   - Return the newly created node.

4. **Create Mirror Image of a Tree (mirrorImage):**
   - If the root is null, return null.
   - Swap the left and right subtrees of the current node.
   - Recursively create mirror images of the left and right subtrees.
   - Return the root node.

5. **Inorder Traversal (inorder):**
   - If the root is null, return.
   - Recursively perform inorder traversal on the left subtree.
   - Print the value of the current node.
   - Recursively perform inorder traversal on the right subtree.

6. **Main Function (main):**
   - Display a menu for user interaction.
   - Based on the user's choice, call the corresponding function to perform the desired operation.
   - Repeat the menu until the user chooses to exit.*/
