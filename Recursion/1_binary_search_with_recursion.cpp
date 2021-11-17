
/**
 * @author By Jatin Vashisht
 * @note   Program of BS to practice recursion
 * @details This is an example of divide and conquer recursion problem, because in each step the array size is divided by 2
 */

#include <iostream>
using namespace std;

/**
 * @brief  Program of Binary Search
 * @param  *arr: array whose elements we are going to search
 * @param  target: target value which is to be searched from array
 * @param  s: starting index from which we have to start searching
 * @param  e: Ending index upto which we have to search
 * @retval index of target value in array if element found, and -1 otherwise
 */
int BinarySearch(int *arr, int target, int s, int e)
{
    int mid = (s + e) / 2; /// Method to find middle index of element
    if (s > e)             /// if start is greater than end index, that means we have traversed whole array and value is not found
    {
        return -1;
    }
    if (target == arr[mid]) /// this statement means we have found the target element and now we will simply return the index of mid element
    {
        return mid;
    }
    if (target < arr[mid]) /// if target is less than element at mid index, then we will search the first half of the array
    {
        return BinarySearch(arr, target, s, mid - 1); /// return the value returned by recursive calling of BinarySearch
    }
    if (target > arr[mid]) /// if target is greater than element at mid index, then we will search second half of the array
    {
        return BinarySearch(arr, target, mid + 1, e); /// return the value returned by recursive calling of BinarySearch
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << BinarySearch(arr, 5, 0, 4)<<"\n";
    cout << BinarySearch(arr, 1, 0, 4)<<"\n";
    cout << BinarySearch(arr, 3, 0, 4)<<"\n";
    cout << BinarySearch(arr, -1, 0, 4)<<"\n";
    return 0;
}
