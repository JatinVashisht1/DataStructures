#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *p = &a;
    cout << "value of p is " << p << " and value of *p is " << *p << "\n";
    int **q = &p;
    cout << "\nvalue of q is " << q                   //q contains address of p
         << "value of *q is " << *q                   //*q contains value of p, i.e, address of a
         << " and value of **q is " << *(*q) << "\n"; //**q contains value at value at *q, i.e, value at p is a, which is 10 here

    int ***r = &q;
    cout << "\nvalue of r is " << r                //r contains address of q
         << "\nvalue of *r is " << *r              //*r contains value at r, i.e, value of q, which contains address of p
         << "\nvalue of **r is " << **r            //**r contains value at value at r, which is value at q, i.e, address of p
         << "\nvalue of ***r is " << ***r << "\n"; //***r means value at value at value at r, which is value at value at q, which is value at p, which is value OF a, i.e, 10
}