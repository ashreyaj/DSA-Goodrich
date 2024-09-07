#include <iostream>
#include <cmath>
using namespace std;

int string_to_int(string s)
{
    int n = 0;
    int size = s.size();
    for (int i=0; i<size; i++)
    {
        n += (s[i]-48) * pow(10, size-i-1); // ASCII of '1' is 48
    }
    return n;
}

int main()
{
    string s = "13531";
    cout << "Integer form of " << s << " is " << string_to_int(s) << endl;
    return EXIT_SUCCESS;
}