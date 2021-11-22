
/**
 * @author Jatin Vashisht
 * @brief Program to find sum of digits of number using recursion
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to return sum of digits of number
 * @param  n: number, sum of whose digits we have to find
 * @param  sum: sum of digits
 * @retval sum of digits of number
 */
int sumOfN(int n, int sum = 0)
{
    // Base Condition
    if (n / 10 == 0)
    {
        return sum + n;
    }
    return n % 10 + sumOfN(n / 10, sum);
}

int main()
{
    cout << sumOfN(808) << "\n";
    cout << sumOfN(1023) << "\n";
    cout << sumOfN(0000) << "\n";
    cout << sumOfN(85) << "\n";
    cout << sumOfN(98) << "\n";
    return 0;
}