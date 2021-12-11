
/**
 * @author Jatin Vashisht
 * @brief  Program to print subset of a string
 * @note   This is based on input output method
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to print subset of a string
 * @note   This is based on input output method
 * @param  ip: string whose subset we have to print
 * @param  op: variable to keep track of output
 * @retval None
 */
void printSubset(string ip, string op)
{

    /// Base condition
    if (ip.empty()) /// we are getting a subset each time input is empty
    {
        cout << op << " "; /// printing subset
        return;
    }
    string op1 = op; /// if we look at recursive tree of this problem, then we will find
    /// in child node output we either take second half of the superset or leave it, op1 and op2 represents same
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0); /// erasing first element of input because it was included in op1 and op2
    printSubset(ip, op2);     /// calling printSubset() recursively for op1 and op2
    printSubset(ip, op1);
}

int main()
{
    printSubset("abc", "");
    return 0;
}