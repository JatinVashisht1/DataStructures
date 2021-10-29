/**
 * By Jatin Vashisht
 * Program to convert infix notation to postfix notation (without paranthesis)
*/

#include<iostream>
#include<string>
using namespace std;

class Stack{
    char data;
    public:
    Stack* next;
    void push(Stack** head, char dat){
        Stack* temp = new Stack();
        temp->data = dat;
        temp->next = *head;
        *head = temp;
    }

    bool isEmpty(Stack* head){
        return head == NULL;
    }

    void pop(Stack** head){
        Stack* temp = new Stack();
        temp = (*head)->next;
        *head = temp;
    }

    char top(Stack* head){
        return head->data;
    }

    void printStack(Stack** head){
        Stack* temp = new Stack();
        temp = *head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }    
};
int precedence(char c){
    switch (c)
    {
    case '+':{
        return 1;
    }
        break;
    case '-':{
        return 1;
    }
        break;
    case '*':{
        return 2;
    }
    break;
    case '/':{
        return 2;
    }
    break;
    default:
        return -1;
    }
}
string infixToPostfix(string s){
    Stack* head = NULL;
    string postfix = "";
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            if(head->isEmpty(head) || precedence(head->top(head)) < precedence(s[i])){
                head->push(&head, s[i]);
            }
            if(precedence(head->top(head)) > precedence(s[i])){
                while(!head->isEmpty(head)){
                    postfix.push_back(head->top(head));
                    head->pop(&head);
                }
            }
        }else{

            postfix.push_back(s[i]);
        }
    }
    while(!head->isEmpty(head)){
                    postfix.push_back(head->top(head));
                    head->pop(&head);
                }
    return postfix;
}
int main(){
       string s = "A+B*C+D-E";
       string post = infixToPostfix(s);
       cout<<post;
}

// + - * /