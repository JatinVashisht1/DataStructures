#include <iostream>
#include <math.h>
using namespace std;

int sum = 0;
/**
 * @brief  This is way one of reversing a number using recursion
 * @note   It is kind of cheating as we have used a global variable to perform our task
 * @param  n: number which is to be reversed
 * @retval None
 */
void rev1(int n)
{
    if (n == 0)
    {
        return;
    }

    int rem = n % 10;     /// rem: stores remainder of the number and adds it to the sum variable
    sum = sum * 10 + rem; /// sum is updated by multiplying it sum with 10 and then adding the last digit of current number to it
    rev1(n / 10);         /// calling rev1 recursively by removing digit at ones place
}

/**
 * @brief  It is a helper function to keep track of how many times a digit of number is to be multiplied by 10
 * @param  n: number which is to be multiplied by 10s
 * @param  digits: number of digits in number n
 * @retval modified value of the number passed
 */
int helper(int n, int digits)
{
    if (n % 10 == 0)
    {
        return n;
    }
    int rem = n % 10;

    return rem * pow(10, digits - 1) + helper(n/10, digits - 1);
}

int rev2(int n)
{

    /**
     * Iometimes we need some additional variables in the argument
     * In that case we create another function
     */

    int digits = (int)(log10(n)) + 1; /// formula to find number of digits in a number
    
    return helper(n, digits);
}

int main()
{
    int n = 6589;
    rev1(n);
    cout << sum << "\n";
    cout << rev2(5896) << "\n";
    return 0;
}
