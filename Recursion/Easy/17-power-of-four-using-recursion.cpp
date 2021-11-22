
/**
 * @author Jatin Vashisht  
 * @brief Program to find nth power of four
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to find nth power of four
 * @param  n: nth power of four
 * @param  i: counter to keep track of power of 4
 * @param  result: variable to store current result, i.e, current power of four
 * @retval nth power of four
 */
int powerOfFour(int n, int i = 1, int result = 1)
{
    if (n == 0)
    {
        return 1;
    }
    // Base Condition
    if (n == i)
    {
        return 4 * result;
    }
    return 4 * powerOfFour(n, i + 1, result);
}

int main()
{
    cout << powerOfFour(0) << "\n";
    cout << powerOfFour(1) << "\n";
    cout << powerOfFour(2) << "\n";
    cout << powerOfFour(3) << "\n";
    cout << powerOfFour(4) << "\n";
    cout << powerOfFour(5) << "\n";
    cout << powerOfFour(6) << "\n";
    return 0;
}