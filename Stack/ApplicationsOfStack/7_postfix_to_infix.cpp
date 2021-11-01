
/**
 * By Jatin Vashisht
 * Program to postfix notation into infix notation
 */

#include <iostream>
using namespace std;
class Stack
{
    Stack *next;

public:
    string data;
    bool isEmpty(Stack *head)
    {
        return head == NULL;
    }
    void push(Stack **head, string x)
    {
        Stack *temp = new Stack();
        temp->data = x;
        if (isEmpty(*head))
        {
            temp->next = NULL;
            *head = temp;
            return;
        }
        else
        {
            temp->next = *head;
            *head = temp;
            return;
        }
    }
    void pop(Stack **head)
    {
        if (isEmpty(*head))
        {
            cout << "Overflow condition\n";
            return;
        }
        else
        {
            Stack *temp = new Stack();
            temp = *head;
            *head = (*head)->next;
            delete (temp);
            return;
        }
    }
    void printStack(Stack *head)
    {

        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << "\n";
    }
};

bool isOperator(char ope)
{
    switch (ope)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    default:
        return false;
    }
}

/**
 * takes a string which has to be converted into infix notation
 */
string postfixToInfix(string s)
{
    Stack *head = NULL;
    for (int i = 0; i < s.length(); i++)
    {
        if (isOperator(s[i]))
        {
            string op1 = head->data;
            head->pop(&head);

            string op2 = head->data;
            head->pop(&head);

            string temp = "(" + op2 + s[i] + op1 + ")";
            head->push(&head, temp);
        }
        else
        {
            head->push(&head, string(1, s[i]));
        }
    }
    return head->data;
}

int main()
{
    string postfix = "AB+C*";
    string infix = postfixToInfix(postfix);
    cout << infix;
    return 0;
}