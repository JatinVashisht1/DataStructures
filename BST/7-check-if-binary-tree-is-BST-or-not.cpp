
/**
 * @author Jatin Vashisht
 * @brief Program to check is a binary tree is BST or not , this program is also possible by tweaking the inorder traversal a bit.
 * Because inorder traversal of a BST give us sorted list
 * T.C = O(n)
 */

#include <iostream>
#include <limits.h>
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
    Node *temp = new Node();
    temp->data = data;
    return temp;
}

void insert(Node **root, int data)
{
    if (*root == NULL)
    {
        return;
    }
    else if (data <= (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else
    {
        insert(&(*root)->right, data);
    }
}

/**
 * @brief  a utility function to return if the Binary tree is true or not
 * @param  *root: root node of Binary Tree
 * @param  minValue: lower bound for checking if node is placed at correct place or not
 * @param  maxValue: upper bound for checking if node is placed at correct place or not
 * @retval boolean, true if Binary Tree is BST or not
 */
bool isBstUtil(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;

    if (root->data > minValue &&
        root->data < maxValue &&
        isBstUtil(root->left, minValue, root->data) &&
        isBstUtil(root->right, root->data, maxValue)
        )
    {
        return true;
    }

    else
        return false;
}

/**
 * @brief  function to check Binary Tree is BST or not
 * @param  root: root node of Binary Tree
 * @retval true if tree is BST and false otherwise
 */
bool isBst(Node* root){
    return isBstUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    Node* root = NULL;
    insert(&root, 55);
    insert(&root, 45);
    insert(&root, 65);
    insert(&root, 35);
    insert(&root, 75);
    cout<<isBst(root)<<"\n";
    return 0;
}