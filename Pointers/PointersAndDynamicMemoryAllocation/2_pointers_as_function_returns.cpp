#include <iostream>
using namespace std;
void printHelloWorld(){
    cout<<"Hello world!\n";
}
int* add(int* a, int* b){
    int c = *a + *b;
    // return &c; //this is not a good practice as in stack on calling other function, the value at memory address of c would be deallocated
    //we should use dynamic memory allocation instead as it is stored in heap and the allocation and deallocation of memory is handled by programmer
    int* ptr; 
    ptr = new int;
    *ptr = *a + *b;
    return ptr;
    /*
        In above case we have allocated the memory in heap and thus it is will not be deallocated even after the function is returned!
    */
}
int main(){
    int a = 5, b = 6;
    int* ptr = add(&a, &b);
    printHelloWorld();
    cout<<*ptr;//it will print correct value even after the execution of add function is over
    delete ptr;
    cout<<*ptr;//now this will print garbage value as we have deallocated the value at memory address stored in ptr
}