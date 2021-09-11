#include<iostream>
using namespace std;
int binarySearch(int a[], int num, int size);
int main(){
    //binary search
    int a[5] = {1, 2, 3, 4, 5};

    cout<<"enter the number you want to search\n";
    int num;
    cin>>num;

    int index = binarySearch(a, num, 5);
    switch(index)
    {
        case -1:
        {
            cout<<"Number is not present in the array\n";
        }
        break;
        default:{
            cout<<"Number is present in array at index "<<index<<"\n";
        }
        break;
    }
}

int binarySearch(int a[], int num, int size)
{
    int L = a[0];
    int H = a[size-1];
    
    while(L<=H)
    {
        int M = L + (H-1)/2;
        // check if number is present at mid
        if(num == a[M])
        {
            return M;
        }
        // if number is less than M
        else if( num < a[M] )
        {
            H = M-1;
        }
        // if number is greater than H
        else{
            L = H + 1;
        }
    }

    return -1;
}

