
/**
 * By Jatin Vashisht
 * Program of Breadth First Traversal in BST, via, Level Order Traversal
 * In this traversal we first print all the elements at same level and then go down towards leaf node
 * T.C = O(n), for all cases and all binary tree
 * S.C = O(1), for best case and S.C = O(n), for worst and average case
 */

#include <iostream>
#include <queue>
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
        *root = getNode(data);
        return;
    }
    else if (data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else
    {
        insert(&(*root)->right, data);
    }
}

/**
 * Function for Level Order Traversal
 * Takes address of root node
 */
void levelOrderTraversal(Node *root)
{
    // return if tree is empty
    if (root == NULL)
    {
        return;
    }

    // declaring queue for pushing and poping tree elements
    queue<Node *> temp;
    // push the root node in queue
    temp.push(root);
    while (!temp.empty())
    {
        // declaring another temporary node to store node at front of queue
        Node *current = temp.front();

        // print the data that is at front of queue
        cout << current->data << " ";

        // now push the left and right childrent of current node if they are not NULL
        if (current->left != NULL)
        {
            temp.push(current->left);
        }
        if (current->right != NULL)
        {
            temp.push(current->right);
        }

        // pop the current node from tree
        temp.pop();
    }
}

int main()
{
    Node *root = NULL;
    insert(&root, 55);
    insert(&root, 45);
    insert(&root, 35);
    insert(&root, 65);
    levelOrderTraversal(root);
    return 0;
}