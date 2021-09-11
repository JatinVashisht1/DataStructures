#include <iostream>
using namespace std;
void insertion_sort(int a[], int N);
int main()
{
    int N;
    cout << "Enter the size of array\n";
    cin >> N;
    int a[N];
    cout << "Enter the elements of array\n";
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    insertion_sort(a, N);
}

void insertion_sort(int a[], int N)
{

    // example array: a = [1 5 9 3 5 7]
    for (int j = 1; j < N; j++)
    {
        // define the key element
        int key = a[j];
        // define i as j-1
        int i = j - 1;
        // run the  loop till i is greater than 0 and ith element of array is greater than the key element
        while (i >= 0 && a[i] > key)
        {
            // if the ith element it greater than key then we move inside the while loop

            // assign value of ith element to i+1 th index
            // in third iteration key = a[j] = 3, and inside while loop the first iteration is a[i] = 9, thus we will assign a[i] to a[i+1], i.e, 9 instead of 3
            a[i + 1] = a[i];
            // decrease i by one, to check wheather the other elements is in correct order or not
            // i was 2 previously so it would be decremented to 1 now
            i = i - 1;
            // assign the key value to i + 1 th position
            // assign a[2] the value of key, i.e, 3 here
            a[i + 1] = key;
        }
    }
    cout << "Sorted array is \n";
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
}