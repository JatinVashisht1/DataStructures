#include <iostream>
#include <math.h>
using namespace std;

int nOZ(int n, int z /*= 0*/)
{
    if (n == 0)
    {
        return z;
    }
    if (n > 0)
    {
        if (n % 10 == 0)
        {
            z++;
        }
        nOZ(n / 10, z); /// why is this giving answer?
    }
}

/**
 * @brief  Helper function for nOZ2. Special pattern, how to pass value to above calls
 * @param  n: number which is to be checked
 * @param  c: current count of zeroes
 * @retval number of zeroes in the number
 */
int helper(int n, int c) /// this function is made in-order to return a number,
/// it may be steps taken to do something, or counting frequency of something in a number(like in this case)
{
    if (n == 0)
    {
        return c;
    }
    int rem = n % 10;
    if (rem == 0)
    {
        return helper(n / 10, ++c);
    }
    return helper(n / 10, c);
}
int nOZ2(int n, int ans)
{
    return helper(n, 0);
}

int main()
{
    cout << nOZ(150236, 0) << "\n";
    cout << nOZ(150036, 0) << "\n";
    /*
    cout << nOZ(1400, 0) << "\n";
    cout << nOZ(10000, 0) << "\n";
    cout << nOZ(0000, 0) << "\n";
    */
    cout << nOZ2(8908, 0) << "\n";
    cout << nOZ2(8900, 0) << "\n";
    return 0;
}