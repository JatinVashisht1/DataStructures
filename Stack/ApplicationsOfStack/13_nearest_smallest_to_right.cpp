
/**
 * By Jatin Vashisht
 * Program to find the nearest smaller element to right of each element of the array
 * This program is also a variation  of NGR
 * Following steps are different from NGR
 * 1. we will push_back the element if (s.top() < arr[i])
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> nSR(int *arr, int size)
{
    stack<int> s;
    vector<int> v;
    for (int i = size - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (!s.empty() && s.top() >= arr[i])
        {
            while (!s.empty() && s.top() >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        else if (!s.empty() && s.top() < arr[i])
        {
            v.push_back(s.top());
        }
        s.push(arr[i]);
    }

    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int a[5] = {1, 4, 2, 5, 3};
    vector<int> v = nSR(a, 5);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}