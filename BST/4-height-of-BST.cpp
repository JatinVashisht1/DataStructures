
/**
 * By Jatin Vashisht
 * Program to find height of BST (height of a tree is height of its root node)
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

int findHeight(Node *root)
{
    if (root == NULL)
    {
        return -1; // height of empty tree is -1
    }
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

int main()
{
    Node *root = NULL;
    insert(&root, 55);
    insert(&root, 45);
    insert(&root, 65);
    insert(&root, 35);
    insert(&root, 85);
    insert(&root, 25);
    cout << findHeight(root) << "\n";
    return 0;
}