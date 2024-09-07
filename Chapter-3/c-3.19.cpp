#include <iostream>
using namespace std;

string reverse_string(string& s, int i, int j)
{
    if(s.size() < 1 || s == "" || i >= j) return "";
    else
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        reverse_string(s, i+1, j-1);
    }
    return s;
}

int main()
{
    string s = "bababa";
    cout << "Reverse of " << s << " is " << reverse_string(s, 0, s.size()-1) << endl;
    return EXIT_SUCCESS;
}