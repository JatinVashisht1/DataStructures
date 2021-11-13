
/**
 * By Jatin Vashisht
 * Program of Optimal Adjacent Removal
 * T.C = O(n), here n is length of string
 * S.C is directly proportional to size of stack, which is dependent on the pattern of string used
 * Stack will be filled most when there is no duplicate element in string, in which case size of stack will be proportional to length of string
 * Stack will be filled least when there is adjacent duplicate elements, in which case stack will contain atmost 1 element at any time
 * S.C = O(1) in best case and S.C = O(n) in worst case
 */

#include <iostream>
#include <stack>
using namespace std;

/**
 * @param string on which operation is to be performed
 * @return size of modified string
 */
int reduceString(string s)
{
    stack<char> temp;
    for (int i = 0; i < s.length(); i++)
    {

        if (temp.empty())
        {
            temp.push(s[i]);
        }
        else if (temp.top() == s[i])
        {
            temp.pop();
        }
        else
        {
            temp.push(s[i]);
        }
    }
    return temp.size();
}

int main()
{
    string s;
    int n;
    cin >> n; /// taking input the number of test cases to be performed
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        cout << reduceString(s) << "\n";
    }
    return 0;
}
