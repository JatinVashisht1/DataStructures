#include<iostream>
#include<memory>
#include<utility>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
// Node* head;
void insertAtNthPosition(Node** head, int data, int pos)//Node** because head contains the address of starting byte of the list and we are passing the address of the head variable in main funciton
// So we have to dereference the address of head and then we will get the pointer to the head of list
{
    Node* ptr = new Node();
        ptr->data = data;
        ptr->next = NULL;
    if(pos==1){
        ptr->next = (*head);
        (*head) = ptr;
        return;
    }

    Node* ptr2 = new Node();
    ptr2 = (*head);
    for(int i = 0; i<pos-2; i++)//pos-2 because it will point to the next position
    {
        ptr2 = ptr2->next;
    }
    ptr->next = ptr2->next;
    ptr2->next = ptr;
}

void printList(Node* head){
    Node* ptr = new Node();
    ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<"  ";
        ptr = ptr->next;
    }
    cout<<"\n";
}

int main(){
    Node* head = NULL;
    // head = NULL;
    insertAtNthPosition(&head, 45, 1);//we are passing the address of head variable
    insertAtNthPosition(&head, 53, 2);
    insertAtNthPosition(&head, 59, 2);
    insertAtNthPosition(&head, 68, 3);
    insertAtNthPosition(&head, 75, 5);
    printList(head);//here we are passing pointer to the head of linked list, i.e, variable head which contains the address of it
}