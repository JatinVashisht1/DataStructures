
/**
 * @author Jatin Vashisht
 * @brief  Program to check if given Binary Tree is BST or not
 * @note   This is just a tweak of Inorder traversal, because inorder traversal give us a sorted list
 * @details In this method, unlike inorder traversal we donot print the current element of tree. But instead we maintain a stack of integer and compare the top element of stack with current element of tree and push it onto stack if s.top() < root->data and we return false if s.top() > root->data
 */

#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
};

Node *getNode(char data)
{
    Node *temp = new Node();
    temp->data = data;
    return temp;
}

void insert(Node **root, char data)
{
    if (*root == NULL)
    {
        *root = getNode(data);
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
 * @brief  return whether the binary tree is BST or not
 * @note   this is just a tweak of inorder traversal
 * @param  *root: root node of tree
 * @retval true if binary tree is BST and false otherwise
 */
bool isBst(Node *root)
{
    stack<int> s;
    if (root == NULL)
    {
        return true;
    }
    else
    {
        isBst(root->left);
        isBst(root->right);
        if (s.empty())
        {
            s.push(root->data);
        }
        else if (s.top() > root->data) /// if previous element was greater than current element, then return false
        {
            return false;
        }
        else
        {
            s.push(root->data);
        }
    }
    return true;
}
int main()
{
    Node *root = NULL;
    insert(&root, 'F');
    insert(&root, 'D');
    insert(&root, 'J');
    insert(&root, 'B');
    insert(&root, 'E');
    insert(&root, 'G');
    insert(&root, 'K');
    insert(&root, 'A');
    insert(&root, 'C');
    insert(&root, 'I');
    cout << isBst(root);
    return 0;
}