
/**
 * @author Jatin Vashisht
 * @brief  Program to skip a string from a sentence or parent string
 */

#include <iostream>
using namespace std;

/**
 * @brief  Function to skip a string from a sentence
 * @param  s: parent string
 * @param  target: string which is to be skipped
 * @param  temp: temporary string which will store string until we get a blank space
 * @param  ans: variable that will store final answer
 * @param  index: variable to keep track of current index
 * @retval modified skipped string
 */
string skipString(string s, string target, string temp = "", string ans = "", int index = 0)
{
    if (s[index] == ' ')
    {
        if (temp == target)
        {
            return skipString(s, target, "", ans, ++index);
        }
        return skipString(s, target, "", ans.append(" " + temp), ++index);
    }

    /// Base Condition
    if (s[index] == '\0')
    {
        if (temp != target)
            ans.append(" " + temp);

        return ans;
    }
    temp.push_back(s[index]);
    return skipString(s, target, temp, ans, ++index);
}

int main()
{
    string parent = "You can do anything you put your mind to - Eminem";
    cout << skipString(parent, "Eminem") << "\n";
    cout << skipString(parent, "You") << "\n";
    cout << skipString(parent, "anything") << "\n";
    cout << skipString(parent, "put") << "\n";
    cout << skipString(parent, "your") << "\n";
    cout << skipString(parent, "mind") << "\n";
    cout << skipString(parent, "to") << "\n";
    cout << skipString(parent, "-") << "\n";
    cout << skipString(parent, "") << "\n";
    cout << skipString("jatin", "jatin") << "\n";
    return 0;
}