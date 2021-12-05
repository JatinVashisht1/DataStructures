
/**
 * @author Jatin Vashisht
 * @brief Program to sort a stack using recursion
 * @note It similar to sorting a vector using recursion
 */

#include <iostream>
#include <stack>
using namespace std;

/**
 * @brief  Function to insert the element at its correct position in stack
 * @param  &s: stack in which element is to be inserted (passed by reference)
 * @param  temp: element which is to be inserted in stack
 * @retval None
 */
void insert(stack<int> &s, int temp)
{
    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

/**
 * @brief  Function to sort a stack
 * @param  &s: stack which we will sort (passed by reference)
 * @retval None
 */
void sortStack(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int temp = s.top();
    s.pop();
    sortStack(s);
    insert(s, temp);
}

/**
 * @brief  Function to print a stack
 * @param  s: stack which is to be printed
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
    sortStack(s);
    printStack(s);
    return 0;
}