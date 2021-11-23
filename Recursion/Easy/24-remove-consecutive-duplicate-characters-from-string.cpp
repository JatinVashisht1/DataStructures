
/**
 * @author Jatin Vashisht
 * @brief  Program to remove duplicate characters from string
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to remove duplicate characters from a string
 * @param  s: string whose duplicate characters has to be removed
 * @param  ans: current resultant modified string
 * @param  index: variable to keep track of index
 * @retval modified string with no duplicate characters
 */
string removeDuplicates(string s, string ans = "", int index = 0)
{
    if (index == s.size() - 1)
    {
        ans.push_back(s[index]);
        return ans;
    }
    if (s[index] == s[index + 1])
    {
        return removeDuplicates(s, ans, index + 1);
    }
    if (s[index] != s[index + 1])
    {
        ans.push_back(s[index]);
        return removeDuplicates(s, ans, index + 1);
    }
    return removeDuplicates(s, ans, index + 1);
}

int main()
{
    cout << removeDuplicates("abccd") << "\n";
    cout << removeDuplicates("abcd") << "\n";
    cout << removeDuplicates("raandom String") << "\n";
    return 0;
}