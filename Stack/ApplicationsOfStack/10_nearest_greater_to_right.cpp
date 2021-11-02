
/**
 * By Jatin Vashisht
 * Program to find nearest greates to right of each element of array
 * We can apply stack when two nested loops i and j such that j loop is nested inside i and j depends upon i
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nGR(int *arr, int size)
{
    stack<int> s;
    vector<int> v;

    for (int i = size - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            v.push_back(-1);
            s.push(arr[i]);
        }
        else if (!s.empty() && s.top() > arr[i])
        {
            v.push_back(s.top());
        }
        else if (!s.empty() && s.top() <= arr[i])
        {
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else if (s.top() >= arr[i])
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}
int main()
{
    int a[5] = {2, 4, 1, 6, 0};
    vector<int> v = nGR(a, 5);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}