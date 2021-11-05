
/**
 * By Jatin Vashisht
 * Program of rainwater trapping problem 
 * This problem looks similar to MAH but both problems have some differences
 * In this problem we have to find absolute maximum elements to right and left of each element of array
 * Then we find how much water can be stored above each building and sum it up and return the summed value
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int* mXL(int *arr, int size)
{
    stack<int> s;
    int *ngl = new int[size];
    s.push(arr[0]);
    ngl[0] = s.top();
    for (int i = 1; i < size; i++)
    {
        if (s.top() > arr[i])
        {
            ngl[i] = s.top();
        }
        else
        {
            s.pop();
            s.push(arr[i]);
            ngl[i] = s.top();
        }
    }
    return ngl;
}

int* mXR(int *arr, int size)
{
    stack<int> s;
    int *ngr = new int[size];
    s.push(arr[size - 1]);
    for (int i = size - 1; i >= 0; i--)
    {
        if (s.top() > arr[i])
        {
            ngr[i] = s.top();
        }
        else
        {
            s.pop();
            s.push(arr[i]);
            ngr[i] = s.top();
        }
    }
    return ngr;
}

int rainWater(int *arr, int size)
{
    int *mxl = mXL(arr, size);
    int *mxr = mXR(arr, size);
    vector<int> water;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        water.push_back(min(mxl[i], mxr[i]) - arr[i]); // to find the amount of water that can be stored on building
        sum += water[i];
    }
    return sum;
}

int main()
{
    int arr[6] = {3, 0, 0, 2, 0, 4};
    int water = rainWater(arr, 6);
    cout << water;
    return 0;
}