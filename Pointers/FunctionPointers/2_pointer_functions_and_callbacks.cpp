#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
int comparison(int a, int b){
    if(a>b) return 1;
    else return -1;
}

int comparison_absolute(int a , int b){
    if(abs(a)>abs(b)) return 1;
    else return -1;
}

void BubbleSort(int *A , int n, int (*compare)(int, int))// function BubbleSort is taking a pointer to function as a parameter
{
    int i, j;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-1; j++){
            if(compare(A[j], A[j+1])>0){
                A[j] = A[j]^A[j+1];
                A[j+1] = A[j]^A[j+1];
                A[j] = A[j]^A[j+1];
            }
        }
    }
}

int main(){
    //callback functions are functions that take pointer to a function as argument
    //it is very similar to the lamda function in Java and Kotlin
    int A[5] = {1, 4, 3, 6, 5};
    BubbleSort(A, 5, comparison);
    for(int i = 0; i<5; i++){
        cout<<A[i]<<" ";
    }

    cout<<"\n";

    int B[5] = {-1, -4, 3, -6, 5};
    BubbleSort(B, 5, comparison_absolute);
    for(int i = 0; i<5; i++){
        cout<<B[i]<<" ";
    }

}