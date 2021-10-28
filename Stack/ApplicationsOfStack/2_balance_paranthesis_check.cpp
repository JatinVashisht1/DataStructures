/**
 * By Jatin Vashisht
 * Program to check balanced paranthesis
*/

#include<iostream>
#include<string>
using namespace std;
class Stack{
    char data;
    Stack *next;

public:
    
    void push(Stack **head, char data)
    {
        Stack *temp = new Stack();
        temp->next = (*head);
        temp->data = data;
        *head = temp;
    }

  
    void pop(Stack **head)
    {
        Stack *temp = new Stack();
        temp = *head;
        *head = (*head)->next;
        delete (temp);
    }

   
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

   
    bool isEmpty(Stack *head)
    {
        return head == NULL;
    }

   
    char top(Stack **head)
    {
        return (*head)->data;
    }
};

/**
 * Function to check for balanced paranthesis
 * Takes a string as argument
*/
bool checkParanthesis(string s){
  Stack* head = NULL;
  
  /**
   * running loop till the length of string
  */
  for(int i = 0; i<s.length(); i++){
      /**
       * Following if statements are used to check whether the closing bracket is complementing with the brackets pushed
       * As the last pushed bracket is to be closed first, these statements are check for that only
      */
    if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
        if(head->isEmpty(head)){
            return false;
    }
    else if(s[i] == ')' && head->top(&head) == '('){
        head->pop(&head);
    }
    else if(s[i] == '}' && head->top(&head) == '{'){
        head->pop(&head);
    }
    else if(s[i] == ']' && head->top(&head) == '['){
        head->pop(&head);
    }
    else{
        return false;
    }
    }
    else {
        head->push(&head, s[i]);
    }
  }
  return head->isEmpty(head);
}
int main(){
    string s = "{()}";
    cout<<checkParanthesis(s)<<"\n";
    string s2 = "{{{)]";
    cout<<checkParanthesis(s2);
}