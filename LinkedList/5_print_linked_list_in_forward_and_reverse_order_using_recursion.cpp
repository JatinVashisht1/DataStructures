#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

/*
    1. In this function we are first printing the data of current node and then calling the function via recursion, thus it will print elements in forward manner

    2. To print List in forward way iterative approach is more efficient as in that case we have to maintain a temporary variable only but here we have to call function again and again.
*/
void printInForward(Node* head)
{
    if(head == NULL){
        cout<<"\n";
        return;
    }

    cout<<head->data<<" ";
    // head = head->next;
    printInForward(head->next);
}

/*
    1. In this function we are first calling the function via recursion and then printing the element, thus the elements will be printed after the recursion stops growing, and when it will end we will have last element of list to print and the will keep printing in reverse order as the function call via recursion will be popped off from stack.

    2. We can use recursion to print the elements in reverse order as using iterative order also we have to maintain record of previous, next and current element.
*/
void printInReverse(Node* head)
{
    if(head == NULL){
        cout<<"\n";
        return;
    }

    printInReverse(head->next);
    cout<<head->data<<" ";
    // head = head->next;
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
int main(){
    Node* head = NULL;

    insertNode(&head, 56, 1);
    insertNode(&head, 66, 2);
    insertNode(&head, 76, 3);
    insertNode(&head, 86, 4);
    insertNode(&head, 96, 5);
    insertNode(&head, 106, 6);

    printInForward(head);
    printInReverse(head);
}