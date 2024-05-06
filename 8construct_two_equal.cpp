/*Create binary tree/binary search tree with n nodes, do following operation
1. Insert a node
2. construct a binary tree from inorder and preorder traversal
3. Check whether two trees are equal.
*/

#include <bits/stdc++.h>
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

bool identical(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    return (root1->data == root2->data && identical(root1->left, root2->left) && identical(root1->right, root2->right));
}

Node *helper(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &inorder_map, int instart, int inend, int &preindex)
{
    if (instart > inend)
        return nullptr;
    int rootval = preorder[preindex++];
    Node *root = new Node(rootval);
    int inindex = inorder_map[rootval];
    root->left = helper(preorder, inorder, inorder_map, instart, inindex - 1, preindex);
    root->right = helper(preorder, inorder, inorder_map, inindex + 1, inend, preindex);
    return root;
}

Node *createTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inorder_map;
    for (int i = 0; i < inorder.size(); i++)
    {
        inorder_map[inorder[i]] = i;
    }
    int preindex = 0;
    return helper(preorder, inorder, inorder_map, 0, inorder.size() - 1, preindex);
}

void inordertraversal(Node *root)
{
    if (root == nullptr)
        return;
    inordertraversal(root->left);
    cout << root->data << " ";
    inordertraversal(root->right);
}

int main()
{
    Node *root = nullptr;
    Node *root2 = nullptr;
    int choice, val;
    vector<int> preorder;
    vector<int> inorder;
    do
    {
        cout << "\nMENU\n";
        cout << "1. Insert node\n";
        cout << "2. Construct tree from inorder and preorder traversal\n";
        cout << "3. Check trees equality\n";
        cout << "4. Exit\n";
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
            cout << "Enter no. of nodes in the tree : ";
            int size;
            cin >> size;
            cout << "Enter inorder traversal: ";
            for (int i = 0; i < size; i++)
            {
                int num;
                cin >> num;
                inorder.push_back(num);
            }
            cout << "Enter preorder traversal: ";
            for (int i = 0; i < size; i++)
            {
                int num;
                cin >> num;
                preorder.push_back(num);
            }
            root2 = createTree(preorder, inorder);
            cout << "Tree constructed successfully.\n";
            cout << "Inorder traversal of constructed tree : ";
            inordertraversal(root2);
            break;
        }
        case 3:
        {
            if (identical(root, root2))
                cout << "Trees are identical.\n";
            else
                cout << "Trees are not identical.\n";
            break;
        }
        case 4:
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
    } while (choice != 4);
    return 0;
}
/*Sure, here's the algorithm for the operations described in the code:

1. **Insert a Node**:
   - Start with the root node.
   - Compare the value to be inserted with the value of the current node.
   - If the value is greater than or equal to the current node's value, move to the right subtree; otherwise, move to the left subtree.
   - Repeat the process until an appropriate empty position is found, then insert the new node there.

2. **Construct a Binary Tree from Inorder and Preorder Traversal**:
   - Given the preorder and inorder traversals of a binary tree, use the following approach:
     - The first element of the preorder traversal is the root of the tree.
     - Find the root's position in the inorder traversal.
     - The elements to the left of the root's position in the inorder traversal represent the left subtree, and the elements to the right represent the right subtree.
     - Recursively construct the left and right subtrees using the above steps.

3. **Check whether two Trees are Equal**:
   - Recursively compare the data of the corresponding nodes in both trees.
   - If the data of the current nodes is equal and the left and right subtrees are also equal, then the trees are identical.
   - Otherwise, the trees are not identical.

This code provides a simple interactive menu-driven interface to perform these operations on binary trees.*/
