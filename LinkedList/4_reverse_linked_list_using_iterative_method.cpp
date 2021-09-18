#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* reverseLinkedList(Node* head)
{
    Node *curr, *pre, *next;
    curr = head;
    pre = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }

    head = pre;
    return head;
}

void insertNode(Node** head, int data, int pos){
    Node* temp = new Node();
    // temp = (*head);
    if(pos == 1){
        temp->data = data;
        temp->next = (*head);
        (*head) = temp;
        return;
    }
    temp->data = data;
    Node* temp2 = (*head);
    for(int i = 0; i<pos - 2; i++){
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
}

void printLinkedList(Node** head){
    Node* temp = new Node();
    temp = (*head);
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<"\n";
}

int main(){
    Node* head = NULL;
    insertNode(&head, 55, 1);
    insertNode(&head, 89, 2);
    insertNode(&head, 74, 3);
    insertNode(&head, 32, 4);
    insertNode(&head, 16, 5);
    printLinkedList(&head);

    head = reverseLinkedList(head);

    printLinkedList(&head);
}