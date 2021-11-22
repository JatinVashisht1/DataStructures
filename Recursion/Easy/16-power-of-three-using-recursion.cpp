
/**
 * @author Jatin Vashisht
 * @brief Program to find nth power of three
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to find power of three using recursion
 * @param  n: number whose power of 3 is to find 
 * @param  i: counter to keep track whether we have reached upto nth power
 * @param  result: variable to store result of current call
 * @retval result: i.e, nth power of three
 */
int powerOfThree(int n, int i = 1, int result = 1)
{
    if (n == 0)
    {
        return 1;
    }
    // Base Condition
    if (i == n)
    {
        return 3 * result;
    }
    return 3 * powerOfThree(n, i + 1, result);
}

int main()
{
    cout << powerOfThree(0) << "\n";
    cout << powerOfThree(1) << "\n";
    cout << powerOfThree(2) << "\n";
    cout << powerOfThree(3) << "\n";
    cout << powerOfThree(4) << "\n";
    cout << powerOfThree(5) << "\n";
    return 0;
}