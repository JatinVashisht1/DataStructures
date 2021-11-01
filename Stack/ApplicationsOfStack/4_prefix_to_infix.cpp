
/**
 * By Jatin Vashisht
 * Converting prefix notation into infix notation
*/

#include<iostream>
#include<string>
using namespace std;
class Stack{
    Stack* next;
    public:
    string data;
    bool isEmpty(Stack *head){
        return head == NULL;
    }
    void push(Stack** head, string x){
        Stack* temp = new Stack();
        temp->data = x;
        if(isEmpty(*head)){
            temp->next = NULL;
            *head = temp;
            return;
        }else{
            temp->next = *head;
            *head = temp;
            return;
        }
    }
    void pop(Stack** head){
        if(isEmpty(*head)){
            cout<<"Overflow condition\n";
            return;
        }
        else{
            Stack* temp = new Stack();
            temp = *head;
            *head = (*head)->next;
            delete(temp);
            return;
        }
    }
    void printStack(Stack* head){
        
        while(head != NULL){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<"\n";
    }
};
bool isOperator(char ope){
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
 * takes string s which has to be converted into infix notation
*/
string prefixToInfix(string s){
    int length = s.length();
    Stack* head = NULL;
    // scan the string s from right to left
    for(int i = length - 1; i>= 0; i--){
        //check if the current character is operand or not
        //if current character is operator then pop last two digits from stack and convert them into notation and push back onto stack
        if(isOperator(s[i])){
          string op1 = head->data;
          head->pop(&head);
          string op2 = head->data;
          head->pop(&head);
          string temp = "(" + op1 + s[i] + op2 + ")";
          head->push(&head, temp);
        }
        //if current character is not operator than we will simply  push the operator onto stack
        else{
            head->push(&head, string(1, s[i]));
        }
    }
    //at the end of evaluation we will be left with infix notation on the stack
    return head->data;
}

int main(){
    string prefix = "*+ABC";
    string infix = prefixToInfix(prefix);
    cout<<infix<<"\n";
    return 0;
}