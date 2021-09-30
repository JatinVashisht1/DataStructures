/* By Jatin Vashisht */

#include <iostream>
using namespace std;

int max(int *a, int size)
{
    int max = *(a + 0);
    for (int i = 0; i < size; i++)
    {
        if (max < *(a + i))
        {
            max = *(a + i);
        }
    }
    return max;
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

/*
    1. In count sort we make a count array of size max(arr) + 1, and initialize it with zero
    2. Then we increase int number of times an element comes in the array by incrementing the value of count[arr[i]]
    3. Then we store the indexes of the count array which are greater than 0 in the original array
    4. We get our sorted array as a result
*/
void countSort(int a[], int count[], int a_size, int c_size)
{
    //incrementing the value at index count[a[i]]
    for (int i = 0; i < a_size; i++)
    {
        count[a[i]]++;
    }

    int k = 0;
    int b[a_size];

    for (int i = 0; i < c_size; i++)
    {
        while (count[i] != 0)
        {
            a[k] = i;
            k++;
            count[i]--;
        }
    }
}

int main()
{
    int N = 8;
    int a[N] = {1, 6, 4, 1, 7, 4, 8, 9};

    //defining the size of count array
    int count_size = max(a, N) + 1;
    //defining count array
    int count[count_size];

    //initializing count array with zero
    for (int i = 0; i < count_size; i++)
    {
        count[i] = 0;
    }

    cout << "Array before sorting: \n";
    printArray(a, N);
    countSort(a, count, N, count_size);
    cout << "Array after sorting\n";
    printArray(a, N);
}