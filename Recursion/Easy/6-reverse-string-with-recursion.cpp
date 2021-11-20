
/**
 * @author Jatin Vashisht
 * @note   This is not fuly right, as it is just printing string in reverse order, not returning it
 */

#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<char> v, int i)
{
    if (i == 0)
    {
        return;
    }
    cout << v[i - 1];
    reverse(v, --i);
}

int main()
{
    vector<char> v = {'a', 'b', 'c', 'd', 'e'};
    reverse(v, v.size());
    cout << "\n";
    vector<char> m = {'j', 'a', 't', 'i', 'n', 'V', 'a', 's', 'h', 'i', 's', 'h', 't'};
    reverse(m, m.size());
}
