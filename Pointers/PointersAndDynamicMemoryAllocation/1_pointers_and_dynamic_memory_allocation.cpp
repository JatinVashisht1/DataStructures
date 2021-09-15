#include<iostream>
using namespace std;
int main(){
    int *p;
    p = new int;//new operator is used to allocate memory in heap and in run time
    *p = 20;
    cout<<*p<<"\n";
    delete p;

    p = new int[5];//it returns pointer to the starting byte of the memory allocated to p
    cout<<"size of p is "<<sizeof(p)<<"\n";
    
    for(int i = 0; i<5; i++){
        *(p+i) = i;
    }

    for(int i = 0; i<5; i++){
        cout<<*(p+i)<<" ";
    }
    cout<<"\n";
        // delete p[];//this expression is not allowed
        // delete [] p;
       int *B;
       B = (int*)realloc(p, 2*sizeof(int));
    for(int i = 0; i<2; i++){
        cout<<B[i]<<"  ";
    }
}
