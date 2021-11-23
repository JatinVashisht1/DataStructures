#include<iostream>
using namespace std;

int nOSTMNZ(int n, int steps = 0){
    if(n==0){
        return steps;
    }
    if(n%2==0){
        return nOSTMNZ(n/2, steps+1);
    }
    if(n%2 == 1){
        return nOSTMNZ(n-1, steps+1);
    }
}

int main(){
cout<<nOSTMNZ(14)<<"\n";
cout<<nOSTMNZ(54)<<"\n";
cout<<nOSTMNZ(0)<<"\n";
cout<<nOSTMNZ(1)<<"\n";
cout<<nOSTMNZ(100)<<"\n";
cout<<nOSTMNZ(101)<<"\n";
return 0;
}