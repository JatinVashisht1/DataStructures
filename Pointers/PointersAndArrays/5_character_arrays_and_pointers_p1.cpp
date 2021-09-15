#include <iostream>
#include <cstring>
using namespace std;

void print(char A[]); //the declaration char A[] is same as char* A
int main()
{
    char c[6] = {'j', 'a', 't', 'i', 'n', '\0'}; //the size of array should be greate than equal to the number of elements we want to store, because the last place is occupied by null character, i.e, '\0'
    
    char *p = c;//name of the array is pointer to its first element or in other words name of the array gives address of the first element of the array

    cout << p[1] << "\n";                                                                           // this is similar to writing (*p+1)
    cout << "Length of array c is: " << strlen(c) << "\nSize of array c is: " << sizeof(c) << "\n"; //'\0' is not counted by strlen() function

    char a[6] = "Jatin";         //we don't have to specify the null character if we pass a string literal to the array, but the size have to be more than elements
    char b[] = "Jatin Vashisht"; //this is also correct way of allocation

    /*
    // char d[];
    // d = "Jatin"   
    This is wrong way of declaring and defining an array 
    */

    print(c);
}

void print(char A[]) //array are always passed by reference to functions in c/c++
{
    while (*A != '\0')
    {
        cout << *A; //writing *A is same as writing A[i], if is index of array
        A++;
    }
    "\n";
}