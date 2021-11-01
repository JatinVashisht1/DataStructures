
/**
 * By Jatin Vashisht
 * Program to convert prefix notation into postfix notation
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
 * takes a string of prefix notation which has to be converted into postfix notation
 */
string prefixToPostfix(string s)
{
    Stack *head = NULL;
    /**
     * Scanning string from right to left
     */
    for (int i = s.length() - 1; i >= 0; i--)
    {
        /**
         * If the scanned character is operator then we will insert the operator between the last two operands pushed onto stack
         * The resultant string is then pushed again onto stack after converting it into postfix notation
         * If the character is not operator then the character is simply pushed onto stack
         */
        if (isOperator(s[i]))
        {
            string op1 = head->data;
            head->pop(&head);

            string op2 = head->data;
            head->pop(&head);

            string temp = op1 + op2 + s[i];
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
    string s = "*+AB+CD";
    string postfix = prefixToPostfix(s);
    cout << postfix;
    return 0;
}