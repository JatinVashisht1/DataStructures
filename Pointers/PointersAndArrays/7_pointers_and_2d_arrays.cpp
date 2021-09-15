#include<iostream>
using namespace std;
int main(){
    int a[2][3] = {1, 2, 3,
                   4, 5, 6};

    cout<<"value of a is "<<a<<" value of *a is "<<*a<<" value of **a is "<<**a<<" \n";
    cout<<"value of a+1 is "<<a+1<<" value of *a+1 is "<<*a+1<<" value of *(*a+1) is "<<*(*a+1)<<" value of *(a+1) + 1 is "<<*(a+1) + 1<<"\n";
    cout<<"value of *(a+1) is "<<*(a+1)<<" value of *a+1 is "<<*a+1<<" value of **(a+1) is "<< **(a+1)<<" value of *(*(a+1) + 1)) is "<<*(*(a+1) + 1);

    
}