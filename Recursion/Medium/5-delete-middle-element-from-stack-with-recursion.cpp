
/**
 * @author Jatin Vashisht
 * @brief  Program to delete middle element of a stack
 */

#include <iostream>
#include <stack>
using namespace std;

/**
 * @brief  Utility function for deleteMiddleElement function
 * @param  &s: reference of stack whose middle element is to be deleted
 * @param  mid: index of middle element
 * @retval None
 */
void deleteUtil(stack<int> &s, int mid)
{
    if (mid == 0)
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    deleteUtil(s, mid - 1);
    s.push(temp); /// we have to push back the element that we popped earlier in order to traverse till middle element
}

/**
 * @brief  Function to delete middle element of stack
 * @param  &s: reference of stack whose middle element is to be deleted
 * @retval None
 */
void deleteMiddleElement(stack<int> &s)
{
    int mid = (s.size() / 2); /// way of finding index of middle element
    deleteUtil(s, mid);
}

/**
 * @brief  Function to print stack elements
 * @param  s: stack whose elements we will print
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
    s.push(4);
    s.push(1);
    s.push(6);
    s.push(3);
    s.push(8);
    printStack(s);
    deleteMiddleElement(s);
    printStack(s);
    return 0;
}