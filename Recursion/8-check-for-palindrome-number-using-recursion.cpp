#include<iostream>
#include<math.h>
using namespace std;

int helper(int n, int digits){
    if(n%10==0){
        return n;
    }
    int rem = n%10;
    return rem * pow(10, digits-1) + helper(n/10, digits-1);
}

int rev(int n)
{

    int digits = (int)(log10(n)) + 1; /// formula to find number of digits in a number
    return helper(n, digits);
}

bool isPal(int n)
{
    return n == rev(n);
}

int main(){
cout<<isPal(1221)<<"\n";
cout<<isPal(1234)<<"\n";
return 0;
}