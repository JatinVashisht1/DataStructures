
/**
 * By Jatin Vashisht
 * Linked List implementation of Queue
 * All operation takes constant time, i.e, Time Complexity = O(n)
*/
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Queue
{
    Node *rear = NULL;
    Node *front = NULL;

public:
    void enqueue(int x)
    {
        Node *temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if (front == NULL && rear == NULL)
        {
            front = rear = temp;
            return;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            return;
        }
    }

    void dequeue()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "Underflow condition\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            Node *temp = new Node();
            temp = front;
            front = front->next;
            delete (temp);
        }
    }

    void printQueue()
    {
        Node *temp = new Node();
        temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
        return;
    }

    void getFront()
    {
        cout << front->data << "\n";
    }
    void getRear()
    {
        cout << rear->data << "\n";
    }
};
int main()
{
    Queue q;
    q.enqueue(55);
    q.enqueue(65);
    q.enqueue(75);
    q.printQueue();
    q.dequeue();
    q.printQueue();

    return 0;
}