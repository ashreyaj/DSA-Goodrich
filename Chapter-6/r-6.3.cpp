#include <iostream>
using namespace std;

template <typename T>
T* rotate_array(T a[], int n, int d)
{
    T* ra = new T[n];
    for (int i=0; i<n; i++)
    {
        ra[i] = a[(i+d)%n];
    }
    return ra;
}

template <typename T>
void display(T* a, int n)
{
    for (int i=0; i<n; i++)
    {
        cout << *(a+i) << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    int d = 3;
    int a[] = {1,2,3,4,5};
    cout << "Input array: " << endl;
    display(a, n);
    cout << "Array rotated " << d << " times is: " << endl;
    int* ra = rotate_array(a, n, d);
    display(ra, n);
    return EXIT_SUCCESS;
}