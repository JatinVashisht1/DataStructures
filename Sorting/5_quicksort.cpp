#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int start, int end){
    int pivot = a[end];
    int pi = start;
    for(int j = start; j<end; j++){
        if(a[j] < pivot){
            swap(&a[j], &a[pi]);
            pi++;
        }
    }
    
    swap(&a[pi], &a[end]);
    return pi;
}

void quicksort(int a[], int start, int end){
    if(start<end){
        int pi = Partition(a, start, end);
        quicksort(a, 0, pi-1);
        quicksort(a, pi+1, end);
    }
}

void printArray(int a[], int size){
    for(int i = 0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    int a[5] = {5, 4, 3, 2, 1};
    quicksort(a, 0, 4);
    printArray(a, 5);
}