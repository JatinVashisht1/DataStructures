/* By Jatin Vashisht */

#include<iostream>
using namespace std;

/**
 * This is array implementation of stack
 * Dynamic array is not used in below case
 * Best time complexity = O(1) (popping)
 * Worst time complexity = O(n) (popping)
 * Average time complexity = o(1) (popping)
*/

class Stack{
    int A[101];
    int top=-1;
    public:

    void push(int data){
        if(top >= 100){
            cout<<"Error: Stack Overflow\n";
            return;
        }
        else{
            A[++top] = data;
        }
    }

    void pop(){
        if(top == -1){
            cout<<"Error: Stack is empty\n";
        }
        else{
            top--;
        }
    }
    
    void printStack(){
        for(int i = 0; i<=top; i++){
            cout<<A[i]<<" ";
        }
        cout<<"\n";
    }

};
int main(){
    Stack s;

    //below statement is written to check what happen when stack is empty and we give pop instruction
    s.pop();

    //following statements are written to check basic implementation of stack
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    s.printStack();
    s.pop();
    s.printStack();
    
   //following loop is implemented to check the condition of stack overflow
    for(int i = 0; i<102; i++){
        s.push(i);
    }

}
