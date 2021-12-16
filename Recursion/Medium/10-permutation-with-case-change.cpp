
/**
 * @brief  Program to find permutation with case change
 * @author Jatin Vashisht
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to find permutations with case change
 * @note   Based on ip/op method [Aditya Verma]
 * @param  ip: variable to keep track of input
 * @param  op: variable to keep track of output
 * @retval None
 */
void solve(string ip, string op)
{
    /// Base condition
    if (ip.empty())
    {
        cout << op << " ";
        return;
    }

    string op1 = op;
    string op2 = op;
    op1.push_back(ip.at(0) - 32);
    op2.push_back(ip.at(0));

    /// Making input small
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
}

int main()
{
    solve("abcd", "");
    return 0;
}