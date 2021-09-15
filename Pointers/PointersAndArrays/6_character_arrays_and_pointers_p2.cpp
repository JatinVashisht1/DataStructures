#include<iostream>
#include<cstring>
using namespace std;

void print(const char* B);
void write(char* B);
int main(){
    char A[20] ="Hello";
    // char* A = "Hello"; //this definition of character array is valid in C language, as it means compile time constant in C, but it is forbidden in C++
    print(A);
    write(A);
    print(A);
}

void print(const char* B)//by defining a pointer constant we cannot modify the value of the memory location by dereferencing the pointer 
{
    // B[0] = 'A'; // this is not allowed if pointer is constant
    while(*B != '\0'){
        cout<<*B;
        B++;
    }
    cout<<"\n";
}

void write(char* B){
    B[0] = 'A';//we can modify value at B by dereferencing it (note that B[0] is same as *(B+0))
}