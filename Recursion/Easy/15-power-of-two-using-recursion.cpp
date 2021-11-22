
/**
 * @author Jatin Vashisht
 * @brief  Program to find nth power of two
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to return nth power of 2
 * @param  n: power of two to find
 * @param  i: counter to keep track of nth power
 * @param  result: current result
 * @retval nth power of two
 */
int powerOfTwo(int n, int i = 1, int result = 1)
{
    if (n == 0)
    {
        return 1;
    }
    if (i == n)
    {
        return result * 2;
    }
    return 2 * powerOfTwo(n, i + 1, result);
}

int main()
{
    cout << powerOfTwo(0) << "\n";
    cout << powerOfTwo(1) << "\n";
    cout << powerOfTwo(4) << "\n";
    cout << powerOfTwo(3) << "\n";
    cout << powerOfTwo(5) << "\n";
    return 0;
}