#include <iostream>
using namespace std;

template <class T>
T power(T x, int n)
{
    if (n == 0) {return 1;}
    if (n%2 == 0) 
    {
        T y = power(x, n/2);
        return y*y;
    }
    else
    {
        T y = power(x, (n-1)/2);
        return x*y*y;
    }
}

int main()
{
    int n = 5;
    float x = 2.3f;
    cout << x << "^" << n << " = " << power(x,n) << endl;
    return EXIT_SUCCESS;
}