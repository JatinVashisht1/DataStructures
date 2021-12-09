
/**
 * @author Jatin Vashisht
 * @brief Function to reverse stack using recursion
 * @note   This is in place solution, i.e, S.C = O(1)
 */

#include <iostream>
#include <stack>
using namespace std;

/**
 * @brief  Function to insert element at correct place in stack
 * @note   This is part of induction step of reverse function
 * @param  &s: stack in which element is to be inserted
 * @param  ele: element which is to be inserted
 * @retval None
 */
void insert(stack<int> &s, int ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }
    int temp = s.top(); /// store top element of stack in a temporary variable
    s.pop();
    insert(s, ele); /// calling insert recursively
    s.push(temp);   /// pushing temporary element back onto stack which was popped earlier
}

/**
 * @brief  Function to reverse a stack
 * @param  &s: stack which is to be reversed
 * @retval None
 */
void reverse(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int temp = s.top(); /// temporary variable to store top variable of stack
    s.pop();            /// popping the stack by one variable
    reverse(s);         /// calling reverse function recursively until it hits base condition
    insert(s, temp);    /// calling insert function to insert temporary variable back to its correct position
}

/**
 * @brief  Function to print stack elements
 * @param  s: stack whose element is to be printed
 * @retval None
 */
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(55);
    s.push(7);
    s.push(9);
    s.push(152);
    printStack(s);
    reverse(s);
    printStack(s);
    return 0;
}