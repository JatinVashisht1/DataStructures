
/**
 * By Jatin Vashisht
 * Program to find minimum and maximum values of a BST via iteretive way
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
 * Function to find minimum element of BST
 * takes root node as input
 */
int findMin(Node *root)
{
    // returning -1 if tree is empty
    if (root == NULL)
    {
        return -1;
    }
    // keep going left until we get a leaf node
    while (root->left != NULL)
    {
        root = root->left;
    }
    // returning data of leave node
    return root->data;
}

/**
 * Function to find maximum element of BST
 * takes root node as input
 */
int findMax(Node *root)
{
    // returns -1 if tree is empty
    if (root == NULL)
    {
        return -1;
    }
    // keep going right until we get a leaf node, or a node with no left child node
    while (root->right != NULL)
    {
        root = root->right;
    }
    // returns data of leaf node
    return root->data;
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
