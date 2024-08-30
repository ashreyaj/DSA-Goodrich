#include<iostream>
#include<string>
using namespace std;

int vowelCount(string s)
{
    int c = 0;
    string vowels = "aeiouAEIOU";
    for (auto x:s)
    {
        if (vowels.find(x) != string::npos) c += 1;
    }
    return c;
}

int main()
{
    string A = "Hello";
    cout << "Number of vowels in " << A << " is " << vowelCount(A) << endl;
    return 0;
}