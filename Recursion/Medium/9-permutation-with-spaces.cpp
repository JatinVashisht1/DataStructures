
/**
 * @author Jatin Vashisht
 * @brief  Program to find Permutation of string with spaces
 * @note   This program uses Ip/Op method [Aditya Verma]
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to print permutation of string with spaces
 * @note   Ip/Op method is used
 * @param  ip: variable to store input
 * @param  op: variable to store output
 * @retval None
 */
void permutation(string ip, string op)
{

    /// Base Condition
    if (ip.empty())
    {
        cout << op << "\n";
        return;
    }

    string op1 = op; /// outputs for future recursive calls
    string op2 = op;
    op1.push_back(' '); /// including space in one output and excluding in other
    op1.push_back(ip.at(0));
    op2.push_back(ip.at(0));

    ip.erase(ip.begin() + 0); /// making input small for next recursive call
    permutation(ip, op1);     /// one recursive call with space included
    permutation(ip, op2);     /// another recursive call with space excluded
}

/**
 * @brief  Function to provide initial input output
 * @note   This function is used because we don't have to include space before first varialble and after last variable
 * @param  *s: parent string (pass by reference)
 * @param  *ip: input string (pass by reference)
 * @param  *op: output string (pass by reference)
 * @retval None
 */
void getInitialInputOutput(string *s, string *ip, string *op)
{
    op->push_back(s->at(0));  /// including first element of string to output
    s->erase(s->begin() + 0); /// erasing first element of string
    *ip = *s;                 /// assigning value of modified parent string to input string
}
int main()
{
    string s = "abc";
    string op = "";
    string ip = "";
    getInitialInputOutput(&s, &ip, &op);
    permutation(ip, op);

    cout<<"----------------\n";

    string s2 = "abcd";
    string op2 = "";
    string ip2 = "";
    getInitialInputOutput(&s2, &ip2, &op2);
    permutation(ip2, op2);
    return 0;
}