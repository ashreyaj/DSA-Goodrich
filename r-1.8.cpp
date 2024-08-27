#include<iostream>
using namespace std;

bool isMultiple(long n, long m)
{
    if (n/m == float(n)/m) { return true; }
    return false;
}

int main()
{
    long n, m;
    n = 4;
    m = 3
    ;
    bool mult = isMultiple(n, m);
    if (mult == 1) {cout << n << " is a multiple of " << m << endl;}
    else {cout << n << " is not a multiple of " << m << endl;}
    return 0;
}