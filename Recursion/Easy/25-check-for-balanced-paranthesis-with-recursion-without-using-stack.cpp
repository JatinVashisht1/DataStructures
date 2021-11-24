
/**
 * @author Jatin Vashisht
 * @brief  Program to check if paranthesis are balanced or not via recursion
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief  Function to check if paranthesis are balanced or not
 * @param  s: string which contains paranthesis
 * @param  track: vector made to store paranthesis according to our need
 * @param  index: variable made to keep track of index
 * @retval true if paranthesis are balanced and false otherwise
 */
bool isBalanced(string s, vector<char> track, int index = 0)
{
    if (index == 0 && s.empty())
    {
        return false;
    }
    if (s[index] == '\0')
    {
        if (track.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (s[index] == '(')
    {
        track.push_back('(');
        return isBalanced(s, track, index + 1);
    }
    if (s[index] == ')')
    {
        if (track.empty())
        {
            return false;
        }
        if (track.back() == '(')
        {
            track.pop_back();
            return isBalanced(s, track, index + 1);
        }
        else if (track.back() == ')')
        {
            return false;
        }
    }
    // return isBalanced(s, track, index+1);
}

int main()
{
    vector<char> track;
    cout << isBalanced("(())", track) << "\n";
    cout << isBalanced("(((()))", track) << "\n";
    cout << isBalanced("()", track) << "\n";
    cout << isBalanced(")))", track) << "\n";
    cout << isBalanced("())))", track) << "\n";
    cout << isBalanced("", track) << "\n";
    cout << isBalanced("(((())))", track) << "\n";
    cout << isBalanced("((((", track) << "\n";
    return 0;
}