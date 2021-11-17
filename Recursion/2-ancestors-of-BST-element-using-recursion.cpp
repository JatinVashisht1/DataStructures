
/**
 * @author Jatin Vashisht
 * @brief Program to print ancestors of a given element from a BST
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



void printAncestors(Node *root, int data)
{
    // static int sum = 0;
    if (root->right == NULL && root->left == NULL)
    {
        return;
    }
    if (root->data == data)
    {
        return;
    }
    if (data < root->data)
    {
        cout << root->data << " ";
        // sum += root->data;
        printAncestors(root->left, data);
    }
    if (data > root->data)
    {
        cout << root->data << " ";
        // sum += root->data;
        printAncestors(root->right, data);
    }
    // cout<<"\n"<<sum;
}

int main()
{
    Node *root = NULL;
    insert(&root, 55);
    insert(&root, 56);
    insert(&root, 54);
    insert(&root, 75);
    insert(&root, 25);
    cout<<"Ancestors of 25 are "; 
    printAncestors(root, 25);
    cout<<"\n";
    cout<<"Ancestors of 55 are "; 
    printAncestors(root, 55);
    cout<<"\n";
    cout<<"Ancestors of 75 are "; 
    printAncestors(root, 75);
    cout<<"\n";
    cout<<"Ancestors of 56 are "; 
    printAncestors(root, 56);
    cout<<"\n";
    cout<<"Ancestors of 54 are "; 
    printAncestors(root, 54);
    cout<<"\n";
    return 0;
}