
/**
 * @author Jatin Vashisht
 * @author   Program to implement linear search using recursion
 */

#include <iostream>
using namespace std;

bool isPresent(int *arr, int target, int size, int index)
{
    if (arr[index] == size)
    {
        return false;
    }
    if (arr[index] == target)
    {
        return true;
    }
    else
    {
        return isPresent(arr, target, size, index + 1);
    }
}

int main()
{
    int arr[5] = {1, 3, 2, 5, 9};
    cout << isPresent(arr, 3, 5, 0) << "\n";
    cout << isPresent(arr, 11, 5, 0) << "\n";
    return 0;
}