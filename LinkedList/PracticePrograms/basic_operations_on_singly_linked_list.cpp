/* By Jatin Vashisht */

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

void insert(Node **head, int data, int position)
{
    Node *temp = new Node();
    temp->data = data;
    if (position == 1)
    {
        temp->next = (*head);
        (*head) = temp;
        return;
    }

    Node *temp2 = new Node();
    temp2 = *head;
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
}

void deleteNode(Node **head, int position)
{
    Node *temp = new Node();
    if (position == 1)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *temp2 = new Node();
    temp2 = *head;
    for (int i = 0; i < position - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp = temp2;
    temp2 = temp2->next;
    temp->next = temp2->next;
    free(temp2);
}

void deleteByValue(Node **head, int data)
{
    Node *temp = new Node();
    int position = 1;
    temp = *head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            deleteNode(head, position);
            return;
        }
        position++;
        temp = temp->next;
    }
    cout << "Value " << data << " not present in the LinkedList\n";
    return;
}

void reverseList(Node **head)
{
    Node *curr, *next, *prev;
    curr = *head;
    prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

void printList(Node *head)
{
    Node *temp = new Node();
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
    free(temp);
}

void printInReverseByRecursion(Node* head){
    if(head == NULL){
        cout<<"\n";
        return;
    }

    printInReverseByRecursion(head->next);
    cout<<head->data<<" ";
}

void printInForwardByRecursion(Node* head){
    if(head == NULL){
        cout<<"\n";
        return;
    }
    cout<<head->data<<" ";
    printInForwardByRecursion(head->next);
}

void reverseListByRecursion(Node** head, Node* p){
    if(p->next == NULL){
        (*head) = p;
        return;
    }

    reverseListByRecursion(head, p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

int main()
{
    Node *head = NULL;

    insert(&head, 88, 1);
    printList(head);

    insert(&head, 100, 2);
    printList(head);

    insert(&head, 200, 2);
    printList(head);

    cout << "---------------------\n";
    cout << "After reversing list\n";
    reverseList(&head);
    printList(head);
    cout << "---------------------\n";

    deleteNode(&head, 2);
    printList(head);

    deleteByValue(&head, 88);
    printList(head);

    deleteByValue(&head, 90);

    insert(&head, 45, 2);
    insert(&head, 68, 2);
    insert(&head, 20, 2);
    printList(head);
    printInReverseByRecursion(head);
    cout<<"\n";
    printInForwardByRecursion(head);

    reverseListByRecursion(&head, head);
    printList(head);
}
