
/**
 * @author Jatin Vashisht
 * @brief  Program for factorial of number
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to find factorial of number
 * @param  n: number whose factorial we have to find
 * @retval factorial of number
 */
int factorial(int n)
{
    if (n < 0)
    {
        throw -1;
    }
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    try
    {
        cout << factorial(5) << "\n";
        cout << factorial(0) << "\n";
        cout << factorial(1) << "\n";
        cout << factorial(10) << "\n";
        cout<<factorial(-1)<<"\n";
    }
    catch (int e)
    {
       cout<<e;
    }
    return 0;
}