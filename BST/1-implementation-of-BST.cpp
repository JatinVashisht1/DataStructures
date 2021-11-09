
/**
 * By Jatin Vashisht
 * Implementation of BST
 * BST is a balanced binary tree, in which Nodes with data smaller than root node is stored to left and Nodes with data greater than root node is stored to right
 * A balanced binary tree is a tree, whose difference between height of left and right node is not greater than a constant K(which is zero mostly, unless specified)
 * In the this implmentation, Nodes are generated dynamically, i.e, in Heap section of the memory
 * T.C of insertion, deletion and searching is O(log n) in case of BST // here log is taken with base 2
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

/**
 * This function returns address of a new dynamically created node
 */
Node *getNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    return temp;
}

/**
 * Function to insert a node in a BSt
 * Takes address of root node and data to be stored
 * T.C for insertion in a BST is O(log n)// here log is taken with base 2
 */
void insert(Node **root, int data)
{
    // simply point the root to a new node with given data
    if (*root == NULL)
    {
        (*root) = getNode(data);
    }
    // if data given is smaller than the data in root node, then again call the insert function recursively by providing address of root->left as root node
    else if (data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    // if data given is greater than the data in root node, then again call the insert function recursively by providing address of root->right as root node
    else
    {
        insert(&(*root)->right, data);
    }
}

/**
 * Function to search a given value from a BST
 * T.C to search an element from BST is O(log N)//here log is taken with base 2
 * takes address of root node and data to be searched
 */
bool search(Node **root, int data)
{
    // if root is NULL, that means tree is empty, in which case return false
    if (*root == NULL)
    {
        return false;
    }
    // if data in the root is equal to the data provided, return true
    else if ((*root)->data == data)
    {
        return true;
    }
    // if data provided is less than root->data, call search function recursively by providing root->left as new root node
    else if (data < (*root)->data)
    {
        search(&(*root)->left, data);
    }
    // if data provided is greater than root->data, call search function recursively by providing root->right as new root node
    else
    {
        search(&(*root)->right, data);
    }
}

int main()
{
    Node *root = NULL;
    insert(&root, 55);
    cout << root->data << "\n";
    insert(&root, 56);
    cout << root->right->data << "\n";
    insert(&root, 54);
    cout << root->left->data << "\n";
    cout << search(&root, 55) << "  " << search(&root, 54) << "  " << search(&root, 22) << "\n";
    return 0;
}
