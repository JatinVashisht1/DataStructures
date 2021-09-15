#include <iostream>
using namespace std;
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;
    for (int i = 0; i < 5; i++)
    {
        cout << "value: " << *p + i << "\naddress: " << p + i << "\n";
        cout << "value: " << *a + i << "\naddress: " << a + i << "\n";
        cout << "---------------------------------------\n";
        //name of the array is the pointer to the first element of the array
        //therefore, int *p = &a[i], is same as int *p = a;
    }
    cout << p[0] << "\n"; //it is similar to *(p+i), and it is also same as writing a[i] or *(a+i)
}