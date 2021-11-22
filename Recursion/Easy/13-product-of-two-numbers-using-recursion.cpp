
/**
 * @author Jatin Vashisht
 * @brief Program to find product of two numbers using recursion
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to find product of two numbers
 * @param  a: first operand
 * @param  b: second operand
 * @param  prod: product of numbers
 * @retval product of numbers 'a' and 'b'
 */
int product(int a, int b, int prod = 0)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    // Base Condition
    if (b == 1)
    {
        return a + prod;
    }
    return product(a, b - 1, prod + a);
}

int main()
{
    cout << product(8, 1) << "\n";
    cout << product(8, 2) << "\n";
    cout << product(8, 3) << "\n";
    cout << product(8, 4) << "\n";
    cout << product(8, 5) << "\n";
    cout << product(0, 0) << "\n";
    return 0;
}