
/**
 * @brief  Program for Kth Symbol in grammar (LeetCode)
 * @author Jatin Vashisht
 * @retval None
 */

#include <iostream>
#include <math.h>
using namespace std;

/**
 * @brief  Function to find Kth symbol in grammar
 * @note   This problem requires observational skills
 * @param  N: Nth row
 * @param  k: kth column
 * @retval value at Nth row and Kth column
 */
int solve(int N, int k)
{
    /// Base condition (given in question)
    if (N == 1 && k == 1)
    {
        return 0;
    }
    int mid = (pow(2, N - 1)) / 2; /// way to find mid of the row
    if (k <= mid)
    {
        return solve(N - 1, k); /// call solve function recursively for solve(N-1, k) if k<=mid, because upto mid of new row, the values are same as N-1th row, i.e, previous row
    }
    else
    {
        return !solve(N, k - mid); /// call solve function recursively for solve(N-1, k - mid) if k>mid, beacuse element after mid in N th row is just complement of N-1th row
    }
}

int main()
{
    cout << solve(4, 1) << "\n";
    cout << solve(4, 2) << "\n";
    cout << solve(4, 3) << "\n";
    cout << solve(3, 2) << "\n";
    return 0;
}
