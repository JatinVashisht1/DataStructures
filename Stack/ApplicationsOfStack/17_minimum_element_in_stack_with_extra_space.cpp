
/**
 *  By Jatin Vashisht
 * Program to get minimum element of stack with extra space
 * This is version is very simple as we just have to create a supporting stack in order to take care of minimum element of stack
 */

#include <iostream>
#include <stack>
using namespace std;

class CustomStack
{
    stack<int> s;
    stack<int> ss;

public:
    void push(int x)
    {
        s.push(x);
        if (ss.empty() || ss.top() >= x)
        {
            ss.push(x);
        }
    }

    int pop()
    {
        int x = s.top();
        if (s.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        else if (s.top() == ss.top())
        {
            ss.pop();
        }
        s.pop();
        return x;
    }

    int getMin()
    {
        if (!ss.empty())
        {
            return ss.top();
        }
        else
        {
            cout << "Stack is empty\n";
            return -1;
        }
    }
};

int main()
{
    CustomStack s;
    cout << s.getMin() << "\n";
    s.push(55);
    s.push(58);
    s.push(15);
    s.push(25);
    cout << s.getMin() << "\n";
    cout << s.pop() << "\n";
    return 0;
}