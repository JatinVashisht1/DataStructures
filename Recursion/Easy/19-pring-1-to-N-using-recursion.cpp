
/**
 * @author Jatin Vashisht
 * @brief  Program to print first N natural numbers
 */

#include <iostream>
using namespace std;
/**
 * @brief  Function to print first 'n' natural numbers
 * @param  n: number of natural numbers to print
 * @retval None
 */
void print1toN(int n)
{
    if (n == 0)
    {
        return;
    }
    print1toN(--n);
    cout << n + 1 << " ";
}

int main()
{
    print1toN(100);
    cout << "\n\n";
    print1toN(50);
    cout << "\n\n";
    print1toN(0);
    cout << "\n\n";
    print1toN(1);
    return 0;
}