
/**
 * By Jatin Vashisht
 * Program to find maximuma nd minimum element from a BST via recursion
 */

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
};
Node *getNode(int data)
{
    Node *root = new Node();
    root->data = data;
    return root;
}

void insert(Node **root, int data)
{
    if (*root == NULL)
    {
        *root = getNode(data);
    }
    else if (data < (*root)->data)
    {
        return insert(&(*root)->left, data);
    }
    else
    {
        return insert(&(*root)->right, data);
    }
}

/**
 * Function to get minimum element of BST
 * takes root node as input
 */
int findMin(Node *root)
{
    // returns -1 if tree is empty
    if (root == NULL)
    {
        return -1;
    }
    // return data of the node if there is no left element present of current root node
    if (root->left == NULL)
    {
        return root->data;
    }
    // keep calling findMin until minimum element if found
    findMin(root->left);
}

/**
 * Function to get maximum element of BST
 * takes root node as input
 */
int findMax(Node *root)
{
    // returng -1 if tree is empty
    if (root == NULL)
    {
        return -1;
    }
    // keep going right until we find a leaf node, or a node whose right child is not present
    else if (root->right == NULL)
    {
        return root->data;
    }
    // keep calling findMax until max element is found
    findMax(root->right);
}
int main()
{
    Node *root = NULL;
    insert(&root, 55);
    insert(&root, 45);
    insert(&root, 65);
    cout << findMin(root) << "\n";
    cout << findMax(root) << "\n";
    return 0;
}