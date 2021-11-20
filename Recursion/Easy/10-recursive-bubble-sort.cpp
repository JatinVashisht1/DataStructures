
/**
 * @author Jatin Vashisht
 * @brief  Program for recursive bubble sort
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to perform bubble sort recursively
 * @param  *arr: array which is to be sorted
 * @param  n: size of array
 * @retval None
 */
void recursiveBubbleSort(int *arr, int n)
{
    if (n == 0) /// Base condition of recursion
    {
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    recursiveBubbleSort(arr, n - 1);
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int arr[5] = {5, 4, 6, 2, 10};
    recursiveBubbleSort(arr, 5);
    printArray(arr, 5);
    return 0;
}
