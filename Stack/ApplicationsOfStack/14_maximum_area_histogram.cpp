
/**
 * By Jatin Vashisht
 * Program to find Maximum area of histogram
 * It is also a variation of NSL and NSR.
 * In this progra we have to find the larges rectangular area in a histogram
 * We will find index of smallest element to right and to left of each element
 * Then we will find width of all the consecutive element by following method: nsr[i] - nsl[i] - 1;
 * Then we find area of each rectangle by multiplying width with height of each element.
 * At the end we return the maximum area of histogram
 */

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nSL(int *arr, int size)
{
    vector<int> v;
    stack<pair<int, int>> s;
    for (int i = 0; i < size; i++)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (!s.empty() && s.top().first >= arr[i])
        {
            while (!s.empty() && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        else if (!s.empty() && s.top().first < arr[i])
        {
            v.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    return v;
}

vector<int> nSR(int *arr, int size)
{
    vector<int> v;
    stack<pair<int, int>> s;
    for (int i = size - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (!s.empty() && s.top().first >= arr[i])
        {
            while (!s.empty() && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        else if (!s.empty() && s.top().first < arr[i])
        {
            v.push_back(s.top().second);
        }

        s.push({arr[i], i});
    }
    reverse(v.begin(), v.end());
    return v;
}

int mAH(int *arr, int size)
{
    vector<int> nsl = nSL(arr, size); // to store index of nearest smallest to left of each element of array
    vector<int> nsr = nSR(arr, size); // to store index of nearest smallest to right of each element of array
    vector<int> width;                // to store width of each building or rectangle of histogram
    vector<int> area;                 // to store area of each rectangle
    for (int i = 0; i < size; i++)
    {
        // calculating width of building or rectangle
        width.push_back(nsr[i] - nsl[i] - 1);
    }
    for (int i = 0; i < size; i++)
    {
        // calculating area of each rectangle by multiplying height of each rectangle to its width
        area.push_back(width[i] * arr[i]);
    }
    int max = area[0];
    for (int i = 1; i < size; i++)
    {
        if (area[i] > max)
        {
            max = area[i];
        }
    }
    // returning maximum area of histogram
    return max;
}

int main()
{
    int arr[7] = {7, 10, 8, 2, 7, 14, 5};
    int max = mAH(arr, 7);
    cout << max;
    return 0;
}