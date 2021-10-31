
/**
 * By Jatin Vashisht
 * In Double Ended Queue or Deque, we can insert and delete elements front either end
 * All operations take constant time, i.e, O(n) = 1
 * Deque donot follow FIFO principle
*/
#include <iostream>
using namespace std;
#define N 100
class Queue
{
    int data[N];
    int front = -1;
    int rear = -1;

public:
    bool isEmpty()
    {
        return front == -1;
    }
    int getFront()
    {
        if (front != -1)
        {
            return data[front];
        }
        else
        {
            cout << "Empty queue\n";
            return -1;
        }
    }
    int getRear()
    {
        if (rear != -1)
        {
            return data[rear];
        }
        else
        {
            cout << "Empty queue\n";
            return -1;
        }
    }
    void enqueueRear(int x)
    {
        if ((rear + 1) % N == front)//in order to implement circular array
        {
            cout << "Queue is full\n";
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            data[rear] = x;
            return;
        }
        else
        {
            rear = (rear + 1) % N;
            data[rear] = x;
            return;
        }
    }
    void enqueueFront(int x)
    {
        if (isEmpty())
        {
            rear = front = 0;
            data[front] = x;
        }
        else if (front == 0)
        {
            cout << "Space unavailable in front\n";
            return;
        }
        else
        {
            front--;
            data[front] = x;
        }
    }
    void dequeueFront()
    {
        if (front == rear)
        {
            rear = front = -1;
        }
        else
        {
            front++;
        }
    }
    void dequeueRear()
    {
        if (isEmpty())
        {
            cout << "Empty Queue\n";
            return;
        }
        else if (rear == front)
        {
            rear = front = -1;
            return;
        }
        else
        {
            rear--;
            return;
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
    }
};
int main()
{
    Queue q;
    q.enqueueRear(55);
    q.enqueueRear(65);
    q.enqueueRear(75);
    q.enqueueRear(85);
    q.enqueueRear(95);
    q.enqueueRear(45);
    q.printQueue();
    q.dequeueFront();
    q.dequeueFront();
    q.dequeueFront();
    q.printQueue();
    q.dequeueRear();
    q.printQueue();
    q.enqueueFront(15);
    q.printQueue();
    return 0;
}
