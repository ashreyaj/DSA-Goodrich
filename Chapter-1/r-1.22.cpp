#include<iostream>
using namespace std;

int times(int n)
{
    int c = 0;
    while(n > 2)
    {
        n /= 2.0;
        c += 1;
    }
    return c;
}

int main()
{
    int n;
    cout << "Enter integer: " << endl;
    cin >> n;
    cout << "Number of times we can divide "<< n << " by 2 before we get a number less than 2 is: " << times(n) << endl;
    return 0;
}