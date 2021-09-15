#include <iostream>
using namespace std;
int main(){
    int a[2][3][4] = 
    {
        {
            {1, 2, 3, 4}, 
            {5, 6, 7, 8}, 
            {9, 10, 11, 12}},
        {
            {13, 14, 15, 16}, 
            {17, 18, 19, 20}, 
            {21, 22, 23, 24}
        }
    };

    cout<<"value of a is "<<a//a is the pointer to starting byte of this 3d array
    <<"\nvalue of *a is "<<*a//*a is the pointer to the starting byte of first 2d array
    <<"\nvalue of **a is "<<**a//**a is the pointer to the starting byte of first 1d array
    <<"\nvalue of ***a is "<<***a//***a is the value at the first position of the first 1d array
    <<"\n\n";

    cout<<"value of a+1 is "<<a+1
    <<"\nvalue of *a+1 is "<<*a+1<<"  for proof: "<<"value of &a[0][1] is "<<&a[0][1]//*a+1 is the pointer to the starting byte of second 2d array
    <<"\nvalue of **a+1 is "<<**a+1<<" for proof: "<<"value of &a[0][0][1]"<<&a[0][0][1]//**a is the pointer to the starting byte of second 1d array
    <<"\nvalue of ***a is "<<***a+1<<" for proof: "<<"value of a[0][0][0] is "<<a[0][0][1]//***a is the value at the second position of the first 1d array
    <<"\n";


}