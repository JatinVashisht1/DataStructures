#include <iostream>
using namespace std;
void DoubleArrayElements(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        *(a + i) = 2 * (*(a + i)); //it is same as writing a[i] = 2*a[i];
    }
}
int main()
{
    int a[] = {3, 5, 6, 7, 3, 7, 9, 11};
    int size = sizeof(a) / sizeof(a[0]);
    cout << "Array before passing to function\n";
    for (int i = 0; i < size; i++)
    {
        cout << *(a + i) << " ";
    }
    DoubleArrayElements(a, size);
    cout << "\n----------------------\nArray after passing to function\n";
    for (int i = 0; i < size; i++)
    {
        cout << *(a + i) << " "; //it is same as writing cout<<a[i];
    }
}