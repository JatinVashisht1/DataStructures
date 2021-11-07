
/**
 * By Jatin Vashisht
 * Maximum product of indexes of next greater on left and right
 * It is just variation of NGL and NGR
 * GFG: https://www.geeksforgeeks.org/maximum-product-of-indexes-of-next-greater-on-left-and-right/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nGR(int *arr, int size)
{
    stack<pair<int, int>> s;
    vector<int> v;
    for (int i = size - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            v.push_back(0);
        }
        else if (!s.empty() && s.top().first <= arr[i])
        {
            while (!s.empty() && s.top().first <= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(s.top().second + 1);
            }
        }
        else if (!s.empty() && s.top().first > arr[i])
        {
            v.push_back(s.top().second + 1);
        }
        s.push({arr[i], i});
    }
    reverse(v.begin(), v.end());
    return v;
}

vector<int> nGL(int *arr, int size)
{
    stack<pair<int, int>> s;
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        if (s.empty())
        {
            v.push_back(0);
        }
        else if (!s.empty() && s.top().first <= arr[i])
        {
            while (!s.empty() && s.top().first <= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(s.top().second + 1);
            }
        }
        else if (!s.empty() && s.top().first > arr[i])
        {
            v.push_back(s.top().second + 1);
        }
        s.push({arr[i], i});
    }
    return v;
}

// maximum product of indices of NGR and NGL
int mPOI(int *arr, int size)
{
    vector<int> l = nGL(arr, size);
    vector<int> r = nGR(arr, size);
    vector<int> pro;
    for (int i = 0; i < size; i++)
    {
        pro.push_back(l[i] * r[i]);
    }
    int max = pro[0];
    for (int i = 1; i < size; i++)
    {
        if (max < pro[i])
        {
            max = pro[i];
        }
    }
    return max;
}

int main()
{
    int arr[5] = {5, 4, 3, 4, 5};
    cout << mPOI(arr, 5);
    return 0;
}