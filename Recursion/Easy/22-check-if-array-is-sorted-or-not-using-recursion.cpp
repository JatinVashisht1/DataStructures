
/**
 * @author Jatin Vashisht
 * @brief  Program to check if array is sorted or not
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to find if array is sorted or not
 * @param  *arr: array which we will check
 * @param  size: size of array
 * @param  index: variable to keep track of current index of array
 * @retval true if array is sorted and false otherwise
 */
bool isSorted(int *arr, int size, int index = 0)
{
    if (index == size - 2)
    {
        return arr[index] > arr[index + 1];
    }
    return (arr[index] > arr[index + 1]) && isSorted(arr, size, index + 1);
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    cout << isSorted(arr, 5) << "\n";
    int arr2[5] = {2, 5, 3, 6, 1};
    cout << isSorted(arr2, 5) << "\n";
    return 0;
}