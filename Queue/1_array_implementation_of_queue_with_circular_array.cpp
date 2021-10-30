/**
 * By Jatin Vashisht
 * Array implementation of queue with circular array
 * you can also use dynamic array incase of overflow condition
 */

#include <iostream>
using namespace std;
class Queue
{
    int data[100];
    int front = -1, rear = -1;

public:
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return rear == 99;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1000;
        }
        else
        {
            return data[front];
        }
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1000;
        }
        else
        {
            return data[rear];
        }
    }

    void enqueue(int x)
    {
        if ((rear + 1) % 100 == front)
        {
            return;
        }
        else if (isEmpty())
        {
            rear = front = 0;
            data[rear] = x;
            return;
        }

        else
        {
            rear = (rear + 1) % 100;
            data[rear] = x;
            return;
        }
    }

    void dequeue()
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (isEmpty())
        {
            return;
        }
        else
        {
            front = (front + 1) % 100;
        }
    }

    void printQueue()
    {
        if (!isEmpty())
        {
            for (int i = front; i <= rear; i++)
            {
                cout << data[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "Queue is empty\n";
        }
    }
};
int main()
{
    Queue *q = new Queue();
    cout<<q->getFront()<<"\n";
    cout<<q->getRear()<<"\n";
    cout<<q->isEmpty()<<"\n";
    cout<<q->isFull();

    cout<<"\n-----------\n";

    q->enqueue(55);
    q->enqueue(65);
    q->enqueue(75);
    q->printQueue();
    q->dequeue();
    q->printQueue();

    cout<<"-----------\n";

    cout<<q->getFront()<<"\n";
    cout<<q->getRear()<<"\n";
    cout<<q->isEmpty()<<"\n";
    cout<<q->isFull()<<"\n";

    return 0;
}
