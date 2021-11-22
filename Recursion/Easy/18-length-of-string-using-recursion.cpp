
/**
 * @author Jatin Vashisht
 * @brief  Program to find length of string recursively
 * @retval None
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to find length of string
 * @param  s: string whose length we have to find
 * @param  i: counter to keep track of whether the current character is '\0'
 * @param  length: variable to store current length of string
 * @retval length of string
 */
int lengthOfString(string s, int i = 0, int length = 0)
{
    // Corner case
    if (s == "")
    {
        return 0;
    }
    // Base Condition
    if (s[i] == '\0')
    {
        return length;
    }
    return 1 + lengthOfString(s, i + 1, length);
}

int main()
{
    cout << lengthOfString("Jatin") << "\n";
    cout << lengthOfString("Vashisht") << "\n";
    cout << lengthOfString("") << "\n";
    cout << lengthOfString(" ") << "\n";
}