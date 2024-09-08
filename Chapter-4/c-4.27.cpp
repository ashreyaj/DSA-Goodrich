#include <iostream>
using namespace std;

double harmonic(int n)
{
    if (n == 1) {return 1;}
    else {return 1.0/n + harmonic(n-1);}
}

int main()
{
    int n = 8;
    cout << "Harmonic sum upto n=" << n << " is " << harmonic(n) << endl;
    return EXIT_SUCCESS;
}