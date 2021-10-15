/* By Jatin Vashisht */

#include <iostream>
using namespace std;
class Stack
{
    int data;
    Stack *next;

public:
    /**
     * In Linked List implementation of Stack, push operation means adding an element at the beginning of the Linked List 
    */
    void push(Stack **head, int data)
    {
        Stack *temp = new Stack();
        temp->next = (*head);
        temp->data = data;
        *head = temp;
    }

   /**
    * In Linked List implementation of Stack, pop operation means removing first element of Linked List
   */
    void pop(Stack **head)
    {
        Stack *temp = new Stack();
        temp = *head;
        *head = (*head)->next;
        delete (temp);
    }

    /**
     * Printing Stack is same as printing Linked List
    */
    void printStack(Stack *head)
    {
        Stack *temp = new Stack();
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
        delete (temp);
    }

    /**
     * isEmpty function returns true if head is NULL
    */
    bool isEmpty(Stack *head)
    {
        return head == NULL;
    }

    /**
     * top function returns first element of Linked List, or the last element pushed in Stack
    */
    int top(Stack **head)
    {
        return (*head)->data;
    }
};
int main()
{
    Stack *head = NULL;
    cout << "isEmpty: " << head->isEmpty(head) << "\n";

    cout << "Stack elements\n";
    head->push(&head, 55);
    head->push(&head, 65);
    head->push(&head, 70);
    head->push(&head, 75);
    head->push(&head, 80);

    head->printStack(head);

    cout << "top: " << head->top(&head) << "\n";

    head->pop(&head);

    cout << "Stack elements\n";
    head->printStack(head);

    cout << "top: " << head->top(&head) << "\n";

    cout << "isEmpty: " << head->isEmpty(head) << "\n";
}