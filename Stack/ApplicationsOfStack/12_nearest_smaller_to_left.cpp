
/**
 * By Jatin Vashisht
 * Program to find nearest smallest element to left of each element of array
 * It is also just a variation of NGR
 * Following changes are made to the code of NGR to find NSL
 * 1. We scan the array from left instead of right
 * 2. We will push_back the element into the vector iff s.top() < arr[i]
 * 3. No need to reverse the vector before returning it
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> nSL(int *arr, int size)
{
    vector<int> v;
    stack<int> s;
    for (int i = 0; i < size; i++)
    {
        if (s.empty())
        {
            v.push_back(-1);
            s.push(arr[i]);
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
    return v;
}

int main()
{
    int a[5] = {2, 5, 3, 6, 1};
    vector<int> v = nSL(a, 5);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}