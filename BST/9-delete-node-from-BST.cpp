
/**
 * @author Jatin Vashisht
 * @brief Program to delete a node from BST
 * @details This program is divided into various cases and subcases.
 * First case is if root == NULL then simply return NULL
 * Second case is if data < root->data, then simply call deleteNode(root->left, data);
 * Third case is if data > root->data, then call deleteNode(root->right, data);
 * Fourth case is the final and important case, i.e, if data == root->data, this case further has many subcases
 *  1. In this case if(root->left == NULL && root->right == NULL), this means that the node is leave case, this this case we can simply delete this node from tree
 *  2. In this case if(root->left == NULL), i.e, node does not have any left child, in this case we first store store root in a temp variable and then point root to root->right, and lastly delete temp from memory
 *  3. In this case if(root->right == NULL), i.e, node does not have right child, in this case we first store root node to a temp variable and then point root to root->left, and lastly delete temp from memory
 *  4. This case means that node have both right and left child/subtree, this step has several sub-steps to proceed.
 *  4.1  First store maximum from right subtree into a temp variable (minimum from left subtree will also work)
 *  4.2 Secondly we will store data of temp into root node
 *  4.3 In third step we will call deleteNode(root->right, data) again and will store returned value in the root node of current subtree.
 * In last we will return root node back to the caller.
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

void inorderTra(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTra(root->left);
    cout << root->data << " ";
    inorderTra(root->right);
}

/**
 * @brief  Function to return node with minimum value from right subtree of given tree
 * @param  *root: is the root node
 * @retval is the address of minimum value from right subtree
 */
Node *findMax(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

/**
 * @brief  Function to delete a given node from the tree
 * @param  *root: root node of tree
 * @param  data: data to be deleted from tree
 * @retval new modified root node
 */
Node *deleteNode(Node *root, int data)
{
    // checking if tree if empty or not
    if (root == NULL)
        return NULL;
    
    // calling deleteNode for left subtree if data < root->data
    else if (data < root->data)
        root->left = deleteNode(root->left, data);
    
    // calling deleteNode for right subtree if data > root->data
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    // this condition will be encountered when we will find data == root->data
    else
    {
        // checking if node is leaf node or not
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return root;
        }

        // check if node has only right child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }

        // check if node has only left child
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }

        // if node have both left and right subtree/child
        else
        {
            Node *temp = findMax(root->right);///finding maximum from right subtree
            root->data = temp->data; /// storing data of maximum data from right subtree into root node
            root->right = deleteNode(root->right, temp->data);/// calling deleteNode again and storing the returned value into root->right
            /**
             * in above statement, we are passing temp->data as data to be removed, which is the maximum element from right subtree, and it will automatically be a leaf node and we know that removal of leave node is very straight forward
            */
        }
        return root;
    }
}

int main()
{
    Node *root = NULL;
    insert(&root, 55);
    insert(&root, 65);
    insert(&root, 25);
    insert(&root, 75);
    insert(&root, 45);
    insert(&root, 35);

    inorderTra(root);

    deleteNode(root, 25);
    deleteNode(root, 65);
    deleteNode(root, 55);

    cout << "\n";
    
    inorderTra(root);
    return 0;
}