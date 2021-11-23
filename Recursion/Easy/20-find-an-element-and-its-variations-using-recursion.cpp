
/**
 * @brief  Variations of finding 
 * @note   
 * @retval None
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief  Function to find index of element in array
 * @param  *arr: array which we have to search
 * @param  target: target element that we will search in array
 * @param  size: size of array
 * @param  index: variable to keep track of index of array
 * @retval index of target element in array
 * */
int findIndex(int *arr, int target, int size, int index = 0)
{
    if (index == size)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    return findIndex(arr, target, size, index + 1);
}

/**
 * @brief  Function to find index of element in array from last index
 * @param  *arr: array which we will search element for
 * @param  target: target element we want to search in array
 * @param  size: size of array
 * @retval index of element in array
 */
int findIndexFromLast(int *arr, int target, int size /*, int index*/)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[size - 1] == target)
    {
        return size - 1;
    }
    return findIndexFromLast(arr, target, size /*, index - 1*/);
}

/**
 * @brief  Function to find all indices that contain target element
 * @param  *arr: array which we have to search for
 * @param  target: target value which we have to find in array
 * @param  size: size of array
 * @param  v: vector which will store indices of target value in array
 * @param  index: variable to keep track of which index we are currently on
 * @retval resultant vector
 */
vector<int> findAllIndices(int *arr, int target, int size, vector<int> v, int index = 0)
{
    if (size == 0)
    {
        return v;
    }
    if (index == size)
    {
        return v;
    }
    if (arr[index] == target)
    {
        v.push_back(index);
    }
    return findAllIndices(arr, target, size, v, index + 1);
}

int main()
{
    int arr[6] = {2, 1, 5, 3, 6, 5};
    cout << findIndex(arr, 5, 6) << "\n";
    cout << findIndex(arr, 0, 6) << "\n";

    cout << "---------------\n";

    cout << findIndexFromLast(arr, 5, 6) << "\n";

    cout << "---------------\n";
    vector<int> temp;
    temp = findAllIndices(arr, 5, 6, temp);
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    return 0;
}