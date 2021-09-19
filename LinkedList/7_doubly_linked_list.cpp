#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};

Node* getNode(int data){
    Node* myNode = new Node();
    myNode->data = data;
    myNode->next = NULL;
    myNode->prev = NULL;
    return myNode;
}

void insertAtHead(Node** head, int data){
    Node* myNode = getNode(data);
    if((*head)==NULL){
        (*head) = myNode;
        return;
    }

    (*head)->prev = myNode;
    myNode->next = (*head);
    (*head) = myNode;
}

void printForward(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

void printReverse(Node* head){
    Node* temp = head;

    if(temp == NULL){
        cout<<"Returning due to null list\n";
        return;
    }
    //going to last node
    while(temp->next !=NULL){
        temp = temp->next;
    }
    // cout<<temp->data<<"  "<<temp->next<<"  "<<temp->prev<<"\n";
    //goint till the temp variable becomes null using prev variable
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<"\n";
}
int main(){
    Node* head = NULL;
    insertAtHead(&head, 53);
    insertAtHead(&head, 58);
    insertAtHead(&head, 65);
    insertAtHead(&head, 75);
    printForward(head);
    cout<<"Printing in reverse order\n";
    printReverse(head);
}