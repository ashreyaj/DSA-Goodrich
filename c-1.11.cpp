#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    int l, s, m; // get larger smaller and modulo
    l = a>b?a:b;
    if (l==a) {s=b;}
    else {s=a;}
    while (true)
    {
        m = l%s;
        if (m == 0) {break;}
        l = s;
        s = m;
    }
    return s;
}

int main()
{
    int x, y;
    cout << "Enter two integers whose GCD should be calculated: " << endl;
    cin >> x >> y;
    cout << "GCD of " << x << " and " << y << " is " << gcd(x,y) << endl;
    return 0;
}