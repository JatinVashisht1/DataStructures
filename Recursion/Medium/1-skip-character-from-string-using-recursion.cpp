
/**
 * @author Jatin Vashisht
 * @brief  Program to skip a character from a string
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to skip a character from a given string
 * @param  s: parent string
 * @param  target: character which has to be skipped
 * @param  modified: string which will store modified new string
 * @param  index: variable to keep track of index
 * @retval modified string
 */
string skipCharacter(string s, char target, string modified = "", int index = 0)
{

    if (s[index] == '\0')
    {
        return modified;
    }

    if (s[index] == target)
    {
        return skipCharacter(s, target, modified, index + 1);
    }
    modified.push_back(s[index]);
    return skipCharacter(s, target, modified, ++index);
}

int main()
{
    cout << skipCharacter("aabcda", 'a') << "\n";
    cout << skipCharacter("aaaa", 'a') << "\n";
    cout << skipCharacter("jatin", 'a') << "\n";
    cout << skipCharacter("nitin", 'i') << "\n";
    cout << skipCharacter("vashisht", 'h') << "\n";
    return 0;
}
