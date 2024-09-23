#include <iostream>
using namespace std;

template <typename T>
T* reverse_array(T* a, const int n)
{
    T* ra = new T[n];
    for (int i=0; i<n; i++)
    {
        ra[i] = a[n-i-1];
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
    int size = 5;
    int A[] = {1, 2, 3, 4, 5};
    int* b = reverse_array(A, size);
    display(b, size);
    return 0;
}