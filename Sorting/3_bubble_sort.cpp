#include <iostream>
using namespace std;
//declare functions
void bubbleSort(int a[], int size); //to sort array
void swap_numbers(int *a, int *b);  //to swap two numbers
void printArray(int a[], int size); //to print array

int main()
{

    cout << "Enter size of array\n";
    int N;
    cin >> N;

    int a[N];
    cout << "Enter array elements\n";
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    bubbleSort(a, N);

    printArray(a, N);
}

// best case: O(n), when array is already sorted
// worst case: O(n^2), when array is in reverse order
// space coplexity: O(1)
void bubbleSort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        //j<size-i-1 because last element will be sorted with each loop
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap_numbers(&a[j], &a[j + 1]);
            }
        }
    }
}

void swap_numbers(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}