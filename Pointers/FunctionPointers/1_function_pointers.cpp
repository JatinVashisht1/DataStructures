#include<iostream>
using namespace std;
int Add(int a, int b){
    return a+b;
}
void printHello(){
    cout<<"Hello world\n";
}

void printHelloName(char* name){
    cout<<"Hello "<<name<<"\n";
}
int main(){
    int (*p)(int, int);
    p = Add;//name of function gives address of the function 
    // the above expression is similar to p = &Add
    int c = p(5, 6);
    cout<<c<<"\n";

    void (*q)();
    q = printHello;
    q();

    void (*r)(char* );
    r = printHelloName;
    r("Jatin");
    

}
