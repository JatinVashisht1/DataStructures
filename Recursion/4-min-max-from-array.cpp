
/**
 * @author Jatin Vashisht
 * @brief Program to find min and max from array, via recursion
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to find minimum element of array, via recursion
 * @param  *arr: array which is to be searched
 * @param  n: size of array
 * @retval minimum element of array
 */
int findMin(int *arr, int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    return min(arr[n - 1], findMin(arr, n - 1)); /// make its recursive tree and stack diagram on paper to understand better
}

int findMax(int *arr, int n)
{
    if (n == 1)
    {
        return arr[n - 1];
    }
    return max(arr[n - 1], findMax(arr, n - 1));
}

int main()
{
    int arr[5] = {1, 5, 0, -5, 80};
    cout << findMin(arr, 5) << "\n";
    cout << findMax(arr, 5) << "\n";
    return 0;
}