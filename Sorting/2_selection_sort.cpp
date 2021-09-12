#include<iostream>
using namespace std;
void selectionSort(int a[], int size);
void swap_numbers(int *a, int *b);
void printArray(int a[], int size);
int main(){
    cout<<"Enter number of elements you want to insert\n";
    int N;
    cin>>N;
    int a[N];

    cout<<"Enter array elements\n";
    for(int i = 0; i<N; i++){
        cin>>a[i];
    }

    selectionSort(a, N);
    cout<<"array after performing selection sort: \n";
    printArray(a, N);

}

// Time Complexity: O(n^2), because of 2 nested loops
// Space Complexity: O(1)
void selectionSort(int a[], int size){
    int min_index = 0;
    int j;
    for(int i = 0; i<size-1; i++){
        min_index = i;
        for(j = i+1; j<size; j++){
            if(a[j]<a[min_index])
            {
                min_index = j;
                swap_numbers(&a[i], &a[min_index]);
            }
        }
    }
}

void swap_numbers(int *a, int *b){
    *a = *a^*b;
    *b = *b^*a;
    *a = *a^*b;
}

void printArray(int a[], int size){
    for(int i = 0; i<size; i++){
        cout<<a[i]<<" ";
    }
}