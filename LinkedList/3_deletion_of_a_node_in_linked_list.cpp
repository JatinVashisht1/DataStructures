#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void deleteNode(Node** head, int key_pos)//takes address of head and key position as arguments
{
    Node* temp = new Node();
    temp = (*head);//we created a temporary variable of Node and pointed it to the head of list
    if(key_pos == 1){
        (*head)->next = temp->next;
        /*if key position is 1, i.e, we have to delete the first element of the list,
         we will simply point the head to the next vaiable the first variable was pointing before*/

        free(temp);//after the operation we will simply free the memory from the heap
    }
    for(int i = 0; i<key_pos - 2; i++){
        temp = temp->next;
    }
    Node* temp2 = new Node();
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void insertNode(Node** head, int pos, int data)//function to insert Node
{
    Node* temp = new Node();
    if(pos == 1){
        temp->next = (*head);
        temp->data = data;
        (*head) = temp;
        return;
    }
    temp->data = data;
    Node* temp2 = (*head);
    for(int i = 0; i<pos-2; i++){
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    }

void printLinkedList(Node** head)//function to print linked list
{
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
    // head->data = 12;
    // head->next = NULL;

    // Node*temp = new Node();
    // temp->data = 54; temp->next = NULL;
    // head->next = temp;

    insertNode(&head, 1, 56);
    insertNode(&head, 2, 57);
    insertNode(&head, 3, 58);
    insertNode(&head, 4, 59);
    printLinkedList(&head);

    deleteNode(&head, 2);
    printLinkedList(&head);

    deleteNode(&head, 3);
    printLinkedList(&head);
}