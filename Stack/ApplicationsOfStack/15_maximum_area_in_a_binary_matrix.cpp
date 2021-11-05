
/**
 * By Jatin Vashisht
 * Program to find maximum area of rectangle inside a binary matrix
 * It is a variation of MAH
 * The difference between MAH and MABM is that in MAH we are given 1d matrix or array and in MABM we are given with 2d array.
 * So in MABM we first convert 2d array into 1d array and apply MAH on each 1d matrix, and return the maximum result
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

vector<int> nSL(vector<int> &arr, int size)
{
    stack<pair<int, int>> s;
    vector<int> v;
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

vector<int> nSR(vector<int> &arr, int size)
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

int mAH(vector<int> &arr, int size)
{
    vector<int> nsl = nSL(arr, size);
    vector<int> nsr = nSR(arr, size);
    vector<int> width;
    vector<int> area;
    for (int i = 0; i < size; i++)
    {
        width.push_back(nsr[i] - nsl[i] - 1);
    }
    for (int i = 0; i < size; i++)
    {
        area.push_back(arr[i] * width[i]);
    }
    int max = area[0];
    for (int i = 1; i < size; i++)
    {
        if (area[i] > max)
        {
            max = area[i];
        }
    }
    return max;
}

int maxArea(int arr[][4], int m, int n)
{
    vector<int> v;
    int mx;
    for (int i = 0; i < n; i++)
    {
        v.push_back(arr[0][i]);
    }
    mx = mAH(v, n);

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // will not apply arr[i][j] + v[j] if arr[i][j] == 0
            if (arr[i][j] == 0)
            {
                v.at(j) = 0;
            }
            else
            {
                v.at(j) = arr[i][j] + v.at(j);
            }
        }
        mx = max(mx, mAH(v, 4));
    }

    return mx;
}

int main()
{
    int a[4][4] = {{0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0}};
    int max = maxArea(a, 4, 5);
    cout << max;
    return 0;
}