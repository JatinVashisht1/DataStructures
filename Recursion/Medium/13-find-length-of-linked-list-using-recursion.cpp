#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};

void insert(Node **head, int position, int data)
{

    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (position == 1)
    {
        temp->next = (*head);
        *head = temp;
        return;
    }

    Node *temp2 = new Node();
    temp2 = *head;
    for (int i = 0; i < position - 2; i++)
    {
        // cout<<"entered for\n";
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

int getLength(Node *head, int count = 0)
{
    if (head == NULL)
    {
        return count;
    }
    getLength(head->next, count + 1);
}

int main()
{
    Node *head = NULL;
    cout << getLength(head) << "\n";
    insert(&head, 1, 55);
    insert(&head, 1, 75);
    insert(&head, 2, 57);
    insert(&head, 3, 14);
    printList(head);
    cout << "\n";
    cout << getLength(head);
    return 0;
}