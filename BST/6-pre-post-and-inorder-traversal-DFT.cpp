
/**
 * By Jatin Vashisht
 * Program for pre, post and inorder traversal (three ways of Depth First Traversal)
 * T.C = O(n), n = number of nodes
 * S.C = O(h), h = height of tree
 * height of tree in worst case is proportional to n and in worst case is proportional to log(n)
 * Therefore, S.C = O(n), in worst case and S.C = O(log n), in best/average case
 */

#include <iostream>
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

    if (data <= (*root)->data)
    {
        insert(&(*root)->left, data);
    }

    else if (data > (*root)->data)
    {
        insert(&(*root)->right, data);
    }
}
/**
 * Function for preorder traversal
 * Takes root node as input
 */
void preorderTra(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // visit root node first and then left and right subtree respectively
    cout << root->data << " ";
    preorderTra(root->left);
    preorderTra(root->right);
}

/**
 * Function for inorder traversal
 * Takes root node as input
 */
void inorderTra(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // visit left subtree and then root node and right subtree respectively
    inorderTra(root->left);
    cout << root->data << " ";
    inorderTra(root->right);
}

/**
 * Function for postorder traversal
 * Takes root node as input
 */
void postorderTra(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // visit left and right subtree first and then root node
    postorderTra(root->left);
    postorderTra(root->right);
    cout << root->data << " ";
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
    preorderTra(root);
    cout << "\n";
    inorderTra(root);
    cout << "\n";
    postorderTra(root);
    return 0;
}