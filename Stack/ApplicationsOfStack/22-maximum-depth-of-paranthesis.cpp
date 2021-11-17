
/**
 * @author Jatin Vashisht
 * @brief Program to get maximum depth of paranthesis
 * @details In this examle we will check the maximum depth of paranthesis.
 * We will maintain two variables that is depth and curr_depth both initialized by zero
 * Then we will run a loop from i = 0 upto target.length()
 * Inside loop check if target[i] == '(', if yes then increase curr_depth by one and update depth with curr_depth if depth < curr_depth
 * Else if target == ')', then check if curr_depth>0, if yes then decrease curr_depth by 1, else return -1, as in which case paranthesis are not balanced
 * In last, if curr_depth != 0, return -1 as in which case paranthesis is not balanced and return depth otherwise.
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * @brief  Function to return Maximum Depth of Paranthesis
 * @param  target: takes target string which contains paranthesis
 * @retval depth of paranthesis
 */
int mDOP(string target)
{
    stack<char> s;      /// stack maintained to check for paranthesis
    int depth = 0;      /// stores overall maximum depth of paranthesis
    int curr_depth = 0; /// stores depth of current depth of paranthesis
    for (int i = 0; i < target.length(); i++)
    {
        if (target[i] == '(')
        {
            curr_depth++; /// increment curr_depth if current character is '('
            if (curr_depth > depth)
            {
                depth = curr_depth; /// update depth with curr_depth, if curr_depth > depth
            }
        }
        else if (target[i] == ')')
        {
            if (curr_depth > 0)
            {
                curr_depth--; /// decrement curr_depth if curr_depth > 0, i.e, paranthesis are balanced
            }
            else
            {
                return -1; /// if curr_depth < 0, this means that paranthesis are not balanced, in which case return -1
            }
        }
    }

    if (curr_depth != 0) /// return -1 if curr_depth != 0, i.e, to ensure that paranthesis are balanced
    {
        return -1;
    }

    return depth;
}

int main()
{
    cout << mDOP("((((A))))((B))");
    return 0;
}