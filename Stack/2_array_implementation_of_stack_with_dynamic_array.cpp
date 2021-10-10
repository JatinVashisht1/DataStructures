#include<iostream>
using namespace std;

/**
 * In array implementation of stack using static arrays we encounter problem of Stack Overflow
 * But using dynamic arrays we can increase the size of array according to requirement
 * In this case we will increase the size of array twice the size previously
 * The T.C will be O(1) for average case 
*/
class Stack{
int top = -1;
int *A = new int[5]; 

public:
    void push(int data){
        if(top==4){
            int *B = new int[(top+1)*2];
            for(int i = 0; i<=top; i++){
                B[i] = A[i];
            }
            A = B;
            A[++top] = data;
            return;
        }
        A[++top] = data;
    }

    void pop(){
        top--;
    }

    bool isEmpty(){
        if(top==-1)
        return true;
        else return false;
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
    cout<<s.isEmpty()<<"\n";
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(25);
    s.push(30);
    s.push(35);
    s.push(40);
    s.push(45);
    s.push(50);

    s.printStack();

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.printStack();
    cout<<s.isEmpty()<<"\n";
}