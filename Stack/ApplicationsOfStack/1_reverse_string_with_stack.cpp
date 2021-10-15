/* By Jatin Vashisht */

#include <iostream>
#include <string>
using namespace std;

class Stack
{
    char *arr = new char[10];
    int top = -1;
    int size = 10;

public:
    void push(int data)
    {
        if (top >= size - 1)
        {
            char *temp = new char[size * 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            arr = temp;
            size = size * 2;
        }
        arr[++top] = data;
    }

    int getSize()
    {
        return size;
    }

    void pop()
    {
        top--;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int getTop()
    {
        return top;
    }

    char getFirstElement()
    {
        return arr[top];
    }

    void printStack()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i];
        }
        cout << "\n";
    }
};

string reverseString(string s)
{
    Stack obj;

    for (int i = 0; i < s.length(); i++)
    {
        obj.push(s[i]);
    }

    int i = 0;
    while (!obj.isEmpty())
    {
        s[i] = obj.getFirstElement();
        obj.pop();
        i++;
    }

    return s;
}

int main()
{
    Stack obj;

    /* Following operations were done in order to validate the functioning of array
    obj.push(55);
    obj.push(60);
    obj.push(65);
    obj.push(70);
    obj.push(75);

    obj.pop();

    obj.printStack();

    obj.pop();
    obj.pop();
    obj.pop();

    obj.printStack();
    */

    string a = "Hi my name is ...  Slim Shady";
    cout << reverseString(a);
    cout << "\n";
    string b = "Jatin Vashisht";
    cout << reverseString(b);
    cout << "\n";
    cout << reverseString("nitin");
    cout << "\n";
    cout << reverseString("Taksha");
}
