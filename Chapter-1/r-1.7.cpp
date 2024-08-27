#include<iostream>
using namespace std;

int sum(int n)
{
    int s = 0;
    for (int i=1; i<n; i++)
    {
        s += i;
    }
    return s;
}

int main()
{
    int N = 9;
    cout << "Sum of all numbers less than " << N << " is " << sum(N) << endl;
    cout << "Answer according to formula N(N+1)/2: " << N*(N-1)/2 << endl; 
    return 0;
}