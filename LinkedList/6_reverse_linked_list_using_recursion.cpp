#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void reverse(Node** head, Node* p){

    //breaking condition for recursion
    //at this point the head will point to the last element of the list
    if(p->next == NULL)
    {
        (*head) = p;
        // cout<<"Entered the if statement\n";
        return;
    }

    reverse(head, p->next);
    Node* q = p->next;
    // q = p->next;
    q->next = p;
    p->next = NULL;
}

void insertNode(Node** head, int data, int pos){
    Node* temp = new Node();
    temp->data = data;
    if(pos == 1){
        temp->next = (*head);
        temp->data = data;
        (*head) = temp;
        return;
    }

    Node* temp2 = new Node();
    temp2 = *head;
    for(int i = 0; i<pos-2; i++){
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

    insertNode(&head, 56, 1);
    insertNode(&head, 66, 2);
    insertNode(&head, 76, 3);
    insertNode(&head, 86, 4);
    insertNode(&head, 96, 5);
    insertNode(&head, 106, 6);

    printLinkedList(&head);

    reverse(&head, head);

    printLinkedList(&head);

}
