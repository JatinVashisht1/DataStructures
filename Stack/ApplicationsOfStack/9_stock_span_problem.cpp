
/**
 * By Jatin Vashisht
 * Program for stock span problem
 * It is just a variation of NGL program
 * In this program the index of the nearest greater element plays important part
 * In this instead of storing only the nearest greater element we also store its index, thus we store pair of element and its index in the stack
 * Instead of pushing element in the resultant vector that we have to return, we store the index of nearest greater to left element also
 * When we are done pushing all elements to the vector, we subtract each element from its current index
 * We do this, in order to calculate till how many elements the element remained greater
 */

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> stockSpanProblem(int *arr, int size)
{
    stack<pair<int, int>> s;
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (!s.empty() && arr[i] >= s.top().first)
        {
            while (!s.empty() && arr[i] >= s.top().first)
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
        else if (!s.empty() && arr[i] <= s.top().first)
        {
            v.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }

    for (int i = 0; i < v.size(); i++)
    {
        // we do following subtraction in order to get the number of elements away nearest greater element is away from current element
        v[i] = i - v[i];
    }
    return v;
}
int main()
{
    int a[7] = {100, 80, 60, 70, 60, 75, 85};
    vector<int> v = stockSpanProblem(a, 7);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}